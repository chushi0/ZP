#pragma once
#include "framework.h"
#include "Card.h"
#include <vector>

/// 纸牌堆
class CardPiles
{
public:
	CardPiles();
	virtual ~CardPiles() = default;

	/// 是否已经没有任何纸牌
	bool Empty() const;
	/// 获取纸牌数量
	int Count() const;
	
	/// 清除纸牌堆所有纸牌
	/// 注意：对 TempPiles 调用此函数，可能会造成内存泄露
	void Clear();

	// 禁止复制
	CardPiles(const CardPiles&) = delete;
	CardPiles operator=(const CardPiles&) = delete;

protected:
	/// 获取顶层纸牌（纸牌堆依旧保留此纸牌）
	const Card* GetTopCard() const;

	/// 纸牌
	std::vector<const Card*> cards;
};

inline bool CardPiles::Empty() const {
	return cards.size() == 0;
}

inline int CardPiles::Count() const {
	return cards.size();
}

inline void CardPiles::Clear() {
	cards.clear();
}