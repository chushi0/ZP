#pragma once
#include "CardPiles.h"

/// 可通过玩家操作将其中纸牌移动到另外的纸牌堆的纸牌堆
/// 通常而言，可能需要 MousePiles 作为中转，但 MousePiles 不继承此类
class MovablePiles : virtual public CardPiles
{
public:
	/// 根据鼠标所点位置，根据游戏规则移除并返回纸牌
	/// 如果不满足游戏规则，则不返回任何纸牌
	virtual std::vector<const Card*> RemoveClickCards(POINT point) = 0;

	/// 提交更改，之前移除的纸牌堆已经加入到另外的牌堆
	/// 此函数用于移动纸牌后对后续行为进行检查
	/// 默认情况下，该函数没有实现
	virtual void CommitChange();

	/// 将已经移除的纸牌堆复原
	/// 该函数将在用户尝试移动部分纸牌但失败后调用
	void RestoreChange(std::vector<const Card*> cards);
};

