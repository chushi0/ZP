#pragma once
#include "MainWindow.h"

class Game;
/// ��Ϸ������
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
	/// ��Ϸ����
	Game* game;
	/// ��Ϸ�Ƿ�ϣ�����պ�������¼�
	bool prevMouse;
	/// ��Ϸ�Ƿ��Ѿ�����
	bool end;

	/// ��Ϸ�����ص�
	static void GameEndCallback(void* ptr);
};

