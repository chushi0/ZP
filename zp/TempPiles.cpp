#include "TempPiles.h"

using std::vector;

TempPiles::TempPiles() : valid(52) {
	// Éú³ÉÖ½ÅÆ
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 13; j++) {
			cards.push_back(new Card((Card::Decor)i, j));
		}
	}
}
void TempPiles::Shuffle() {
	for (int i = 51; i > 0; i--) {
		std::swap(cards[i], cards[rand() % i]);
	}
}

TempPiles::~TempPiles() {
	for (int i = 0; i < 52; i++) {
		delete cards[i];
	}
	cards.clear();
}

vector<const Card*> TempPiles::GetCards(int n) {
	if (n > valid) n = valid;
	vector<const Card*> result;
	while (n-- > 0) {
		result.push_back(cards[--valid]);
	}
	return result;
}