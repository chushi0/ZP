#pragma once
#include "CardPiles.h"

/// 临时纸牌堆，用于游戏开始时向其它牌堆分牌，不支持绘图操作
/// 在分配完纸牌后，该纸牌堆依旧保留纸牌对象，析构时一并消除
class TempPiles : public CardPiles
{
public:
	TempPiles();
	virtual ~TempPiles();

	/// 洗牌
	void Shuffle();

	/// 获取 X 张纸牌
	/// 如果剩余纸牌已经不足，则返回所有剩余的纸牌
	std::vector<const Card*> GetCards(int count);
	/// 获取剩余全部纸牌
	std::vector<const Card*> GetAllCards();

private:
	/// 剩余未分配的纸牌数
	int valid;
};

inline std::vector<const Card*> TempPiles::GetAllCards() {
	return GetCards(52);
}