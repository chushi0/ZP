#pragma once
#include "MainWindow.h"

class Game;
/// 游戏主窗口
class GameWindow : public MainWindow
{
public:
	GameWindow();
	virtual ~GameWindow() override;

protected:
	virtual void WndClass(LPCWSTR lpClassName, WNDCLASSEX& wndClassEx) const override;
	virtual void CommandEvent(int wmId) override;
	virtual void PaintEvent(Gdiplus::Graphics& canvas) override;
	virtual void SizeEvent(int w, int h) override;
	virtual void MouseDownEvent(POINT point) override;
	virtual void MouseMoveEvent(POINT point) override;
	virtual void MouseUpEvent(POINT point) override;

private:
	/// 游戏对象
	Game* game;
	/// 游戏是否希望接收后续鼠标事件
	bool prevMouse;
	/// 游戏是否已经结束
	bool end;

	/// 游戏结束回调
	static void GameEndCallback(void* ptr);
};

