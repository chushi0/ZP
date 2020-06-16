// zp.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "GameWindow.h"

using namespace Gdiplus;

#pragma comment(lib, "gdiplus.lib")

// 全局变量:
HINSTANCE hInstance;
HINSTANCE hPrevInstance;
LPWSTR lpCmdLine;
int nCmdShow;

// 函数前向声明
void InitEnv();
int MessageLoop();

/// 主函数
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow) {

	::hInstance = hInstance;
	::hPrevInstance = hPrevInstance;
	::lpCmdLine = lpCmdLine;
	::nCmdShow = nCmdShow;

	InitEnv();

	GameWindow w;
	w.CreateWindowHandle();
	w.Move(w.GetWindowRect().left, w.GetWindowRect().top, 900, 700);
	w.Show(nCmdShow);

	return MessageLoop();
}

/// 初始化环境
void InitEnv() {
	// 初始化GDI+
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR m_gdiplusToken;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);
	// 加载资源
	R::LoadResources();
}

/// 消息循环
int MessageLoop() {
	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ZP));
	MSG msg;

	while (GetMessage(&msg, nullptr, 0, 0)) {
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}