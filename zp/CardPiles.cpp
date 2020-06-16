#include "CardPiles.h"

CardPiles::CardPiles() : cards({}) {
}

const Card* CardPiles::GetTopCard() const {
	int c = cards.size();
	if (c == 0) return nullptr;
	return cards[c - 1];
}