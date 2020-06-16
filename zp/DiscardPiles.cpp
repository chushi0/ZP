#include "DiscardPiles.h"

using std::vector;

void DiscardPiles::PushCard(const Card* card) {
	cards.push_back(card);
}

vector<const Card*> DiscardPiles::PopCards() {
	vector<const Card*> cards;
	while (!Empty()) {
		cards.push_back(GetTopCard());
		CardPiles::cards.pop_back();
	}
	return cards;
}

void DiscardPiles::DrawPiles(Gdiplus::Graphics& canvas) const {
	if (!Empty()) {
		auto card = GetTopCard();
		card->Draw(canvas, true, rectPosition);
	}
}

vector<const Card*> DiscardPiles::RemoveClickCards(POINT point) {
	vector<const Card*> res;
	if (Empty()) {
		return res;
	}
	res.push_back(GetTopCard());
	cards.pop_back();
	return res;
}