#pragma once
#include "OperablePiles.h"
#include "DrawablePiles.h"
#include "MovablePiles.h"

/// 已经解决的纸牌堆
class SuitPiles : public OperablePiles, public DrawablePiles, public MovablePiles
{
public:
	/// 确定该纸牌堆所要解决的花色
	SuitPiles(Card::Decor decor);

	/// 判断当前纸牌堆是否已满
	/// “已满”表示已经无法再加入新的纸牌
	/// 当所有的 SuitPiles 满时，可认为游戏结束
	bool Full() const;

	virtual bool CanOperate(std::vector<const Card*> cards) const override;
	virtual void Operate(std::vector<const Card*> cards) override;
	virtual void DrawPiles(Gdiplus::Graphics& canvas) const override;
	virtual std::vector<const Card*> RemoveClickCards(POINT point) override;

private:
	/// 纸牌堆所要解决的花色
	const Card::Decor decor;
};

inline bool SuitPiles::Full() const {
	return cards.size() == 13;
}