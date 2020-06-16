#pragma once

#include "framework.h"
#include <string>

/// ���ڴ������ڵĻ���
class MainWindow
{
public:
	/// ����һ�����ڣ�ӵ��һ�����⼰�����ࡣ
	MainWindow(LPCWSTR lpWindowTitle, LPCWSTR lpClassName);
	/// �ͷŴ���
	virtual ~MainWindow();

	/// �������ھ��
	/// ����ô�����δע�ᣬ����ע��
	void CreateWindowHandle();

	/// ��ʾ�������
	void Show();
	/// �����������
	void Hide();
	/// ��ָ��ģʽ��ʾ�������
	/// ģʽΪ winuser.h ��������� SW_ ��ͷ�ĺ�
	void Show(int nCmdShow);
	/// �ر��������
	void Close();
	/// ˢ�´��ڿͻ���
	void Update();
	/// �޸Ĵ���λ�úʹ�С
	void Move(int x, int y, int w, int h);

	/// ��ȡ���ھ���λ��
	RECT GetWindowRect() const;
	/// ��ȡ���ڿ��
	LONG GetWindowWidth() const;
	/// ��ȡ���ڸ߶�
	LONG GetWindowHeight() const;

	// ��ֹ����
	MainWindow(const MainWindow&) = delete;
	MainWindow operator=(const MainWindow&) = delete;

protected:
	/// �Ըô����������ϸ����
	/// ����������д��ʵ�ָ��ӹ���
	/// ע�⣺������дʱ *����* ���ø���˷������˷��������˱�֤�����������еı�Ҫ����
	virtual void WndClass(LPCWSTR lpClassName, WNDCLASSEX& wndClassEx) const;
	/// �˵���ѡ���¼�
	virtual void CommandEvent(int wmId);
	/// ��ͼ�¼�
	virtual void PaintEvent(Gdiplus::Graphics& canvas);
	/// ���������¼�
	virtual void DestroyEvent();
	/// ���ڴ�С�ı��¼�
	virtual void SizeEvent(int w, int h);
	/// ����������
	virtual void MouseDownEvent(POINT point);
	/// ����ƶ��������������ʱ��
	virtual void MouseMoveEvent(POINT point);
	/// ������̧��
	virtual void MouseUpEvent(POINT point);

private:
	/// ����б�Ҫ��ע�ᴰ����
	void RegisterWndClassIfNeed(LPCWSTR lpClassName) const;
	/// �������ڶ��󣬲���ȡ����
	void InitWndClass(LPCWSTR lpWindowTitle, LPCWSTR lpClassName);
	/// ���ڴ���ص�
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	/// ���ھ��
	HWND hWnd;

	/// ���ڱ��⡢������
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