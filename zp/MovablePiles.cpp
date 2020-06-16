#include "MovablePiles.h"

void MovablePiles::CommitChange() {}

void MovablePiles::RestoreChange(std::vector<const Card*> cards) {
	assert(cards.size());
	for (int i = 0; i < cards.size(); i++) {
		CardPiles::cards.push_back(cards[i]);
	}
}