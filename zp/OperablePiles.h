#pragma once
#include "CardPiles.h"

/// 可通过玩家操作向其中加入纸牌的纸牌堆
/// 加入纸牌堆前应先判断是否可以加入，然后再调用加入纸牌堆的方法
/// 通常而言，可能需要 MousePiles 作为中转，但 MousePiles 不继承此类
class OperablePiles : virtual public CardPiles
{
public:

	/// 判断是否可以将给定的纸牌堆加入到当前纸牌堆
	virtual bool CanOperate(std::vector<const Card*> cards) const = 0;

	/// 将给定的纸牌堆加入到当前纸牌堆
	virtual void Operate(std::vector<const Card*> cards) = 0;
};
