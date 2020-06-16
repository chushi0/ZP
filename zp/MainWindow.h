#pragma once

#include "framework.h"
#include <string>

/// 用于创建窗口的基类
class MainWindow
{
public:
	/// 构造一个窗口，拥有一个标题及所属类。
	MainWindow(LPCWSTR lpWindowTitle, LPCWSTR lpClassName);
	/// 释放窗口
	virtual ~MainWindow();

	/// 创建窗口句柄
	/// 如果该窗口尚未注册，则先注册
	void CreateWindowHandle();

	/// 显示这个窗口
	void Show();
	/// 隐藏这个窗口
	void Hide();
	/// 以指定模式显示这个窗口
	/// 模式为 winuser.h 中所定义的 SW_ 开头的宏
	void Show(int nCmdShow);
	/// 关闭这个窗口
	void Close();
	/// 刷新窗口客户区
	void Update();
	/// 修改窗口位置和大小
	void Move(int x, int y, int w, int h);

	/// 获取窗口矩形位置
	RECT GetWindowRect() const;
	/// 获取窗口宽度
	LONG GetWindowWidth() const;
	/// 获取窗口高度
	LONG GetWindowHeight() const;

	// 禁止复制
	MainWindow(const MainWindow&) = delete;
	MainWindow operator=(const MainWindow&) = delete;

protected:
	/// 对该窗口类进行详细定义
	/// 允许子类重写以实现复杂功能
	/// 注意：子类重写时 *必须* 调用父类此方法，此方法设置了保证该类正常运行的必要参数
	virtual void WndClass(LPCWSTR lpClassName, WNDCLASSEX& wndClassEx) const;
	/// 菜单项选择事件
	virtual void CommandEvent(int wmId);
	/// 绘图事件
	virtual void PaintEvent(Gdiplus::Graphics& canvas);
	/// 窗口销毁事件
	virtual void DestroyEvent();
	/// 窗口大小改变事件
	virtual void SizeEvent(int w, int h);
	/// 鼠标左键按下
	virtual void MouseDownEvent(POINT point);
	/// 鼠标移动（仅当左键按下时）
	virtual void MouseMoveEvent(POINT point);
	/// 鼠标左键抬起
	virtual void MouseUpEvent(POINT point);

private:
	/// 如果有必要，注册窗口类
	void RegisterWndClassIfNeed(LPCWSTR lpClassName) const;
	/// 创建窗口对象，并获取其句柄
	void InitWndClass(LPCWSTR lpWindowTitle, LPCWSTR lpClassName);
	/// 窗口处理回调
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	/// 窗口句柄
	HWND hWnd;

	/// 窗口标题、窗口类
	std::wstring strWindowTitle, strWindowClass;
};

inline void MainWindow::Show() {
	Show(SW_SHOW);
}

inline void MainWindow::Hide() {
	Show(SW_HIDE);
}

inline void MainWindow::Close() {
	DestroyWindow(hWnd);
}