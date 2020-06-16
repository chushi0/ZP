#pragma once
#include "DrawablePiles.h"
#include "TempPiles.h"

/// 牌库区的纸牌堆，点击后纸牌将移动至弃牌堆
class DeckPiles : public DrawablePiles
{
public:
	
	/// 从临时纸牌堆初始化当前纸牌堆
	/// 注意：该方法将获取 TempPiles 中的全部剩余纸牌
	void InitCards(TempPiles& piles);

	/// 弹出顶层纸牌
	const Card* PopCard();
	/// 将纸牌重新按顺序放入
	void PushCards(std::vector<const Card*> cards);

	virtual void DrawPiles(Gdiplus::Graphics& canvas) const override;
};

inline void DeckPiles::InitCards(TempPiles& piles) {
	PushCards(piles.GetAllCards());
}