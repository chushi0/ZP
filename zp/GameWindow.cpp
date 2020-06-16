#include "GameWindow.h"
#include "Game.h"

GameWindow::GameWindow() :
	MainWindow(L"纸牌", L"ZP_GameWindow"),
	prevMouse(false),
	end(false) {
	game = new Game();
	game->Callback() = GameEndCallback;
	game->CallbackPtr() = this;
}

GameWindow::~GameWindow() {
	delete game;
}

void GameWindow::WndClass(LPCWSTR lpClassName, WNDCLASSEX& wcex) const {
	MainWindow::WndClass(lpClassName, wcex);
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ZP));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDR_GAMEMENU);
}

void GameWindow::CommandEvent(int wmId) {
	switch (wmId) {
	case ID_EXIT:
		Close();
		break;
	case ID_NEW_GAME:
	{
		if (!end && MessageBox(NULL, L"是否放弃当前关卡开始新的游戏？", L"新游戏", MB_YESNO | MB_ICONQUESTION) == IDNO) {
			break;
		}
		delete game;
		game = new Game;
		game->WindowSizeChange(GetWindowWidth(), GetWindowHeight());
		game->Callback() = GameEndCallback;
		game->CallbackPtr() = this;
		end = false;
		prevMouse = false;
		Update();
		break;
	}
	case ID_RESTART:
	{
		int result = MessageBox(NULL, L"是否重新开始当前关卡？", L"重新开始", MB_YESNO | MB_ICONQUESTION);
		if (result == IDYES) {
			auto seed = game->Seed();
			delete game;
			game = new Game(seed);
			game->WindowSizeChange(GetWindowWidth(), GetWindowHeight());
			game->Callback() = GameEndCallback;
			game->CallbackPtr() = this;
			end = false;
			Update();
			prevMouse = false;
		}
		break;
	}
	case ID_ABOUT:
		MessageBox(NULL, L"这就是纸牌。", L"关于纸牌", MB_OK | MB_ICONINFORMATION);
		break;
	}
}

void GameWindow::PaintEvent(Gdiplus::Graphics& canvas) {
	Gdiplus::Bitmap cache(GetWindowWidth(), GetWindowHeight());
	Gdiplus::Graphics* graphics = Gdiplus::Graphics::FromImage(&cache);
	Gdiplus::SolidBrush pen({ 255,255,255 });
	graphics->FillRectangle(&pen, 0, 0, GetWindowWidth(), GetWindowHeight());
	game->DrawGameScene(*graphics);
	canvas.DrawImage(&cache, 0, 0, GetWindowWidth(), GetWindowHeight());
	delete graphics;
}

void GameWindow::SizeEvent(int w, int h) {
	game->WindowSizeChange(w, h);
}

void GameWindow::MouseDownEvent(POINT point) {
	if (end) {
		prevMouse = false;
		return;
	}
	if (!prevMouse) {
		prevMouse = game->MousePress(point);
		Update();
	}
}

void GameWindow::MouseMoveEvent(POINT point) {
	if (prevMouse) {
		game->MousePositionChange(point);
		Update();
	}
}

void GameWindow::MouseUpEvent(POINT point) {
	if (prevMouse) {
		game->MouseRelease(point);
		Update();
	}
	prevMouse = false;
}

void GameWindow::GameEndCallback(void* ptr) {
	GameWindow* thiz = (GameWindow*)ptr;
	assert(thiz);
	thiz->end = true;
	MessageBox(NULL, L"游戏结束：您赢了。", L"游戏结束", MB_OK);
}