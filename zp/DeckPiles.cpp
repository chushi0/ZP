#include "DeckPiles.h"


const Card* DeckPiles::PopCard() {
	auto card = GetTopCard();
	cards.pop_back();
	return card;
}

void DeckPiles::PushCards(std::vector<const Card*> cards) {
	for (int i = 0; i < cards.size(); i++) {
		CardPiles::cards.push_back(cards[i]);
	}
}

void DeckPiles::DrawPiles(Gdiplus::Graphics& canvas) const {
	if (!Empty()) {
		auto card = GetTopCard();
		card->Draw(canvas, false, rectPosition);
	} else {
		Gdiplus::Pen pen1({ 127, 127, 127, 127 }, 3), pen2({127, 127, 127},7);
		canvas.DrawRectangle(&pen1, rectPosition);
		double x = rectPosition.X + rectPosition.Width / 2;
		double y = rectPosition.Y + rectPosition.Height / 2;
		double r = rectPosition.Width / 3;
		canvas.DrawArc(&pen2, Gdiplus::RectF(x - r, y - r, r * 2, r * 2), 0, 360);
	}
}