#include "TablePiles.h"

using std::vector;

TablePiles::TablePiles() :
	hideCount(0) {
}

void TablePiles::InitCards(TempPiles& piles, int n) {
	std::vector<const Card*> cards = piles.GetCards(n);
	assert(cards.size() == n);
	for (auto card : cards) {
		CardPiles::cards.push_back(card);
	}
	hideCount = n - 1;
}

vector<const Card*> TablePiles::RemoveClickCards(POINT point) {
	vector<const Card*> result;
	if (Empty()) {
		return result;
	}
	point.y -= rectPosition.Y;
	// ��������
	double width = rectPosition.Width;
	double height = width * 3 / 2;
	double offset = 0;
	if (cards.size() > 1) {
		offset = min((rectPosition.Height - height) / (cards.size() - 1), width / 5);
	}
	// ������λ��
	// ����ǰ (count - 1) �ţ����� offset * i <= y < offset * (i + 1) ����Ϊ�ڵ��λ��
	// �������һ�ţ����� offset * i <= y < offset * i + height ����Ϊ�ڵ��λ��
	for (int i = 0; i < cards.size() - 1; i++) {
		if (point.y >= offset * i && point.y < offset * (i + 1)) {
			// �ж��Ƿ�����϶�
			// ֻ�а�������ֽ�����ڣ��·���ֽ�ƶ�����˳������϶�
			// һ����˵��ֻҪû�б����أ���ô��Щֽ�ƶ��ǿ����϶���
			if (hideCount <= i) {
				// �ƶ�ֽ��
				for (int j = i; j < cards.size(); j++) {
					result.push_back(cards[j]);
				}
				cards.resize(i);
				return result;
			}
		}
	}
	// �ж����һ��
	// ���һ��һ���ǿ��Ա��϶���
	if (point.y >= offset * (cards.size() - 1) && point.y < offset * (cards.size() - 1) + height) {
		result.push_back(GetTopCard());
		cards.pop_back();
	}

	return result;
}

void TablePiles::CommitChange() {
	if (hideCount && hideCount == cards.size()) {
		hideCount--;
	}
}

bool TablePiles::CanOperate(std::vector<const Card*> cards) const {
	if (cards.size() == 0) return false;
	auto thisLast = CardPiles::GetTopCard();
	auto thatFirst = cards[0];
	if (!thisLast) return thatFirst->GetPoint() == 13;
	return thisLast->GetColor() != thatFirst->GetColor() && thatFirst->GetPoint() + 1 == thisLast->GetPoint();
}

void TablePiles::Operate(std::vector<const Card*> cards) {
	assert(cards.size());
	for (int i = 0; i < cards.size(); i++) {
		CardPiles::cards.push_back(cards[i]);
	}
}

void TablePiles::DrawPiles(Gdiplus::Graphics& canvas) const {
	double width = rectPosition.Width;
	double height = width * 3 / 2;
	if (Empty()) {
		Gdiplus::Pen pen({ 127, 127, 127, 127 }, 3);
		canvas.DrawRectangle(&pen, Gdiplus::RectF(rectPosition.X, rectPosition.Y, width, height));
		return;
	}
	double offset = 0;
	if (cards.size() > 1) {
		offset = min((rectPosition.Height - height) / (cards.size() - 1), width / 5);
	}
	for (int i = 0; i < cards.size(); i++) {
		cards[i]->Draw(canvas, i >= hideCount, Gdiplus::RectF(rectPosition.X, rectPosition.Y + offset * i, width, height));
	}
}