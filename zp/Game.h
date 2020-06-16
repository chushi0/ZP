#pragma once

#include "TempPiles.h"
#include "TablePiles.h"
#include "SuitPiles.h"
#include "DeckPiles.h"
#include "DiscardPiles.h"
#include "MousePiles.h"

/// 游戏对象，管理全部游戏对象、逻辑等
class Game
{
public:
	/// 函数回调，表示游戏已经结束
	typedef void (*GameEndCallback)(void* ptr);

	/// 以随机随机种子生成
	Game();
	/// 以指定随机种子生成
	Game(long seed);

	/// 用于设置或获取函数回调
	GameEndCallback& Callback();
	/// 用于设置或获取函数回调私有指针
	void*& CallbackPtr();
	/// 以上两个函数的 const 版本
	const GameEndCallback& Callback() const;
	void* const& CallbackPtr() const;
	/// 用于获取随机数种子
	long Seed() const;

	/// 窗口大小改变
	void WindowSizeChange(int width, int height);
	/// 鼠标左键按下
	/// 如果游戏不关心当前事件，则返回 false
	bool MousePress(POINT point);
	/// 鼠标左键抬起
	void MouseRelease(POINT point);
	/// 鼠标位置移动（左键按下时）
	void MousePositionChange(POINT point);
	/// 绘制游戏场景
	void DrawGameScene(Gdiplus::Graphics& canvas) const;

	// 禁止复制
	Game(const Game&) = delete;
	Game operator=(const Game&) = delete;

private:
	/// 用于发牌和游戏结束后析构的临时纸牌堆
	TempPiles tempPiles;
	/// 在桌面上的 7 个主要纸牌堆
	TablePiles tablePiles[7];
	/// 标记问题已解决的 4 个纸牌堆
	SuitPiles suitPiles[4];
	/// 牌库和弃牌所用的纸牌堆
	DeckPiles deckPiles;
	DiscardPiles discardPiles;
	/// 鼠标对应的纸牌堆
	MousePiles mousePiles;

	/// 标记游戏是否已经结束
	bool finish;
	/// 游戏结束回调
	GameEndCallback callback;
	/// 回调函数用到的私有指针
	void* callbackPtr;

	/// 随机数种子
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