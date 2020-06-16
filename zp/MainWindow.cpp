#include "MainWindow.h"
#include <map>
#include <string>

using std::map;
using std::wstring;

MainWindow::MainWindow(LPCWSTR lpWindowTitle, LPCWSTR lpClassName) :
	hWnd(0), strWindowTitle(lpWindowTitle), strWindowClass(lpClassName) {
}

MainWindow::~MainWindow() {
	DestroyWindow(hWnd);
}

void MainWindow::CreateWindowHandle() {
	assert(!hWnd);
	RegisterWndClassIfNeed(strWindowClass.c_str());
	InitWndClass(strWindowTitle.c_str(), strWindowClass.c_str());
}

void MainWindow::Show(int nCmdShow) {
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
}

void MainWindow::Update() {
	InvalidateRect(hWnd, NULL, false);
}

void MainWindow::Move(int x, int y, int w, int h) {
	MoveWindow(hWnd, x, y, w, h, true);
}

RECT MainWindow::GetWindowRect() const {
	RECT rect;
	::GetWindowRect(hWnd, &rect);
	return rect;
}

LONG MainWindow::GetWindowWidth() const {
	RECT rect = GetWindowRect();
	return rect.right - rect.left;
}

LONG MainWindow::GetWindowHeight() const {
	RECT rect = GetWindowRect();
	return rect.bottom - rect.top;
}

void MainWindow::WndClass(LPCWSTR lpClassName, WNDCLASSEX& wcex) const {
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = MainWindow::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = sizeof(LONG_PTR);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.hInstance = hInstance;
	wcex.lpszClassName = lpClassName;
}

void MainWindow::CommandEvent(int wmId) {}

void MainWindow::PaintEvent(Gdiplus::Graphics& canvas) {}

void MainWindow::DestroyEvent() {}

void MainWindow::SizeEvent(int w, int h) {}

void MainWindow::MouseDownEvent(POINT point) {}

void MainWindow::MouseMoveEvent(POINT point) {}

void MainWindow::MouseUpEvent(POINT point) {}

void MainWindow::RegisterWndClassIfNeed(LPCWSTR lpClassName) const {
	// 用于记录哪些窗口类已经注册
	static map<wstring, void*> regWndClasses;
	wstring clsName = lpClassName;
	if (regWndClasses.find(clsName) == regWndClasses.end()) {
		WNDCLASSEX wndClassEx = {};
		WndClass(lpClassName, wndClassEx);
		RegisterClassEx(&wndClassEx);
		regWndClasses[clsName] = 0;
	}
}

void MainWindow::InitWndClass(LPCWSTR lpWindowTitle, LPCWSTR lpClassName) {
	hWnd = CreateWindow(lpClassName, lpWindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	assert(hWnd);
	SetWindowLongPtr(hWnd, 0, (LONG_PTR)this);
}

LRESULT MainWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
#ifdef CallWndFunc
#undef CallWndFunc
#endif
#define CallWndFunc(func, ...)	\
	(((MainWindow*)GetWindowLongPtr(hWnd, 0))->func(__VA_ARGS__))	// 调用 MainWindow 类中对应函数
	switch (message) {
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		CallWndFunc(CommandEvent, wmId);
		return 0;
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		Gdiplus::Graphics* graphics = Gdiplus::Graphics::FromHDC(hdc);
		CallWndFunc(PaintEvent, *graphics);
		EndPaint(hWnd, &ps);
		delete graphics;
		return 0;
	}
	case WM_SIZE:
	{
		int w = CallWndFunc(GetWindowWidth);
		int h = CallWndFunc(GetWindowHeight);
		CallWndFunc(SizeEvent, w, h);
		return 0;
	}
	case WM_LBUTTONDOWN:
	{
		int x = (int)(short)LOWORD(lParam);
		int y = (int)(short)HIWORD(lParam);
		CallWndFunc(MouseDownEvent, { x, y });
		return 0;
	}
	case WM_LBUTTONUP:
	{
		int x = (int)(short)LOWORD(lParam);
		int y = (int)(short)HIWORD(lParam);
		CallWndFunc(MouseUpEvent, { x,y });
		return 0;
	}
	case WM_MOUSEMOVE:
	{
		if (wParam & MK_LBUTTON) {
			int x = (int)(short)LOWORD(lParam);
			int y = (int)(short)HIWORD(lParam);
			CallWndFunc(MouseMoveEvent, { x,y });
			return 0;
		} else {
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	case WM_DESTROY:
		CallWndFunc(DestroyEvent);
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
#undef CallWndFunc
}