#include "MousePiles.h"

MousePiles::MousePiles() :
	fromPiles(nullptr) {
}

bool MousePiles::GetCardsFromPiles(MovablePiles* piles, POINT point) {
	assert(!fromPiles);
	auto cards = piles->RemoveClickCards(point);
	if (cards.size() == 0) return false;
	for (int i = 0; i < cards.size(); i++) {
		CardPiles::cards.push_back(cards[i]);
	}
	fromPiles = piles;
	return true;
}

bool MousePiles::PutCardsToPiles(OperablePiles* piles) {
	assert(fromPiles);

	if (!piles) {
		goto operate_fail;
	}
	if (((CardPiles*)fromPiles) == ((CardPiles*)piles)) {
		goto operate_fail;
	}

	if (piles->CanOperate(cards)) {
		piles->Operate(cards);
		fromPiles->CommitChange();
		fromPiles = nullptr;
		cards.clear();
		return true;
	}

operate_fail:
	fromPiles->RestoreChange(cards);
	cards.clear();
	fromPiles = nullptr;
	return false;
}

void MousePiles::DrawPiles(Gdiplus::Graphics& canvas) const {
	if (Empty()) {
		return;
	}
	double width = rectPosition.Width;
	double height = width * 3 / 2;
	double offset = width / 5;
	for (int i = 0; i < cards.size(); i++) {
		cards[i]->Draw(canvas, true, Gdiplus::RectF(rectPosition.X, rectPosition.Y + offset * i, width, height));
	}
}