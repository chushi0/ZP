#pragma once

#include "TempPiles.h"
#include "TablePiles.h"
#include "SuitPiles.h"
#include "DeckPiles.h"
#include "DiscardPiles.h"
#include "MousePiles.h"

/// ��Ϸ���󣬹���ȫ����Ϸ�����߼���
class Game
{
public:
	/// �����ص�����ʾ��Ϸ�Ѿ�����
	typedef void (*GameEndCallback)(void* ptr);

	/// ����������������
	Game();
	/// ��ָ�������������
	Game(long seed);

	/// �������û��ȡ�����ص�
	GameEndCallback& Callback();
	/// �������û��ȡ�����ص�˽��ָ��
	void*& CallbackPtr();
	/// �������������� const �汾
	const GameEndCallback& Callback() const;
	void* const& CallbackPtr() const;
	/// ���ڻ�ȡ���������
	long Seed() const;

	/// ���ڴ�С�ı�
	void WindowSizeChange(int width, int height);
	/// ����������
	/// �����Ϸ�����ĵ�ǰ�¼����򷵻� false
	bool MousePress(POINT point);
	/// ������̧��
	void MouseRelease(POINT point);
	/// ���λ���ƶ����������ʱ��
	void MousePositionChange(POINT point);
	/// ������Ϸ����
	void DrawGameScene(Gdiplus::Graphics& canvas) const;

	// ��ֹ����
	Game(const Game&) = delete;
	Game operator=(const Game&) = delete;

private:
	/// ���ڷ��ƺ���Ϸ��������������ʱֽ�ƶ�
	TempPiles tempPiles;
	/// �������ϵ� 7 ����Ҫֽ�ƶ�
	TablePiles tablePiles[7];
	/// ��������ѽ���� 4 ��ֽ�ƶ�
	SuitPiles suitPiles[4];
	/// �ƿ���������õ�ֽ�ƶ�
	DeckPiles deckPiles;
	DiscardPiles discardPiles;
	/// ����Ӧ��ֽ�ƶ�
	MousePiles mousePiles;

	/// �����Ϸ�Ƿ��Ѿ�����
	bool finish;
	/// ��Ϸ�����ص�
	GameEndCallback callback;
	/// �ص������õ���˽��ָ��
	void* callbackPtr;

	/// ���������
	long seed;
};

inline Game::GameEndCallback& Game::Callback() {
	return callback;
}

inline void*& Game::CallbackPtr() {
	return callbackPtr;
}

inline const Game::GameEndCallback& Game::Callback() const {
	return callback;
}

inline void* const& Game::CallbackPtr() const {
	return callbackPtr;
}

inline long Game::Seed() const {
	return seed;
}