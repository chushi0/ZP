#include "SuitPiles.h"

SuitPiles::SuitPiles(Card::Decor decor) :
	decor(decor) {
}

bool SuitPiles::CanOperate(std::vector<const Card*> cards) const {
	if (cards.size() != 1) return false;
	auto card = cards[0];
	return card->GetDecor() == decor && card->GetPoint() == Count() + 1;
}

void SuitPiles::Operate(std::vector<const Card*> cards) {
	assert(cards.size() == 1);
	CardPiles::cards.push_back(cards[0]);
}

void SuitPiles::DrawPiles(Gdiplus::Graphics& canvas) const {
	if (!Empty()) {
		auto card = GetTopCard();
		card->Draw(canvas, true, rectPosition);
	} else {
		Gdiplus::Pen pen({ 127, 127, 127, 127 }, 3);
		canvas.DrawRectangle(&pen, rectPosition);
		HBITMAP hBmp[] = { R::heartOnly, R::diamondOnly, R::spadeOnly, R::clubsOnly };
		Gdiplus::Bitmap bmp(hBmp[decor], NULL);
		canvas.DrawImage(&bmp, rectPosition);
	}
}

std::vector<const Card*> SuitPiles::RemoveClickCards(POINT point) {
	std::vector<const Card*> result;
	if (!Empty()) {
		auto card = GetTopCard();
		cards.pop_back();
		result.push_back(card);
	}
	return result;
}