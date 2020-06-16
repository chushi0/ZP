#pragma once
#include "DrawablePiles.h"
#include "MovablePiles.h"
#include "OperablePiles.h"

// 跟随鼠标的纸牌堆，由玩家直接控制
class MousePiles : public DrawablePiles
{
public:
	MousePiles();

	/// 尝试从指定纸牌堆获取纸牌
	/// 如果成功获取，则返回 true，否则返回 false
	bool GetCardsFromPiles(MovablePiles* piles, POINT point);
	/// 尝试将纸牌放入纸牌堆
	/// 如果成功，则返回 true
	/// 如果失败，则将纸牌堆放回来源纸牌堆，并返回 false
	/// 如果来源与目标相同，则认为失败
	/// 如果目标参数为空，则认为失败
	bool PutCardsToPiles(OperablePiles* piles);

	virtual void DrawPiles(Gdiplus::Graphics& canvas) const override;

private:
	/// 记录当前所有的纸牌来源
	MovablePiles* fromPiles;
};

