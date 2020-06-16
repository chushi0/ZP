#include "Game.h"
#include <ctime>

Game::Game() :
	suitPiles{ Card::Decor::Heart, Card::Decor::Spade, Card::Decor::Clubs, Card::Decor::Diamond },
	finish(false),
	callback(nullptr),
	callbackPtr(nullptr) {
	seed = clock();
	srand(seed);
	tempPiles.Shuffle();
	for (int i = 0; i < 7; i++) {
		tablePiles[i].InitCards(tempPiles, i + 1);
	}
	deckPiles.InitCards(tempPiles);
}

Game::Game(long seed) :
	suitPiles{ Card::Decor::Heart, Card::Decor::Spade, Card::Decor::Clubs, Card::Decor::Diamond },
	finish(false),
	callback(nullptr),
	callbackPtr(nullptr),
	seed(seed) {
	srand(seed);
	tempPiles.Shuffle();
	for (int i = 0; i < 7; i++) {
		tablePiles[i].InitCards(tempPiles, i + 1);
	}
	deckPiles.InitCards(tempPiles);
}

void Game::WindowSizeChange(int width, int height) {
	// 水平方向，将宽度分隔为 8 份，每一份的大小即为纸牌宽度，其中一份作为间隔
	// 竖直方向，纸牌高度为宽度的 4/3 倍
	// 对于部分高度可无限延伸的纸牌堆，限制高度为窗口高度
	// 左右留白与上下留白相同
	double cardWidth = width / 8.0;
	double cardHeight = cardWidth * 3.0 / 2.0;
	double spaceWidth = cardWidth / 10.0;
	double xStart[7];
	for (int i = 0; i < 7; i++) {
		xStart[i] = (spaceWidth + cardWidth) * i + spaceWidth;
	}
	double yStart[2], yHeight[2];
	yStart[0] = spaceWidth;
	yHeight[0] = cardHeight;
	yStart[1] = cardHeight + spaceWidth * 2;
	yHeight[1] = height - spaceWidth - yStart[1];
	deckPiles.Rect() = Gdiplus::RectF(xStart[0], yStart[0], cardWidth, yHeight[0]);
	discardPiles.Rect() = Gdiplus::RectF(xStart[1], yStart[0], cardWidth, yHeight[0]);
	for (int i = 0; i < 4; i++) {
		suitPiles[i].Rect() = Gdiplus::RectF(xStart[3 + i], yStart[0], cardWidth, yHeight[0]);
	}
	for (int i = 0; i < 7; i++) {
		tablePiles[i].Rect() = Gdiplus::RectF(xStart[i], yStart[1], cardWidth, yHeight[1]);
	}
	auto& rect = mousePiles.Rect();
	rect.Width = cardWidth;
	rect.Height = cardHeight;
}

bool Game::MousePress(POINT point) {
	MousePositionChange(point);
	Gdiplus::PointF p(point.x, point.y);
	for (int i = 0; i < 7; i++) {
		if (tablePiles[i].RectContains(p) && mousePiles.GetCardsFromPiles(&tablePiles[i], point)) {
			return true;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (suitPiles[i].RectContains(p) && mousePiles.GetCardsFromPiles(&suitPiles[i], point)) {
			return true;
		}
	}
	if (discardPiles.RectContains(p) && mousePiles.GetCardsFromPiles(&discardPiles, point)) {
		return true;
	}
	if (deckPiles.RectContains(p)) {
		if (deckPiles.Empty()) {
			auto cards = discardPiles.PopCards();
			deckPiles.PushCards(cards);
		} else {
			auto card = deckPiles.PopCard();
			discardPiles.PushCard(card);
		}
	}
	return false;
}

void Game::MouseRelease(POINT point) {
	Gdiplus::PointF p(point.x, point.y);
	for (int i = 0; i < 7; i++) {
		if (tablePiles[i].RectContains(p)) {
			mousePiles.PutCardsToPiles(&tablePiles[i]);
			return;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (suitPiles[i].RectContains(p)) {
			mousePiles.PutCardsToPiles(&suitPiles[i]);
			// 检查游戏结束
			for (int j = 0; j < 4; j++) {
				if (!suitPiles[j].Full()) return;
			}
			if (callback)
				callback(callbackPtr);
			return;
		}
	}
	mousePiles.PutCardsToPiles(nullptr);
}

void Game::MousePositionChange(POINT point) {
	auto& rect = mousePiles.Rect();
	rect.X = point.x - rect.Width / 2;
	rect.Y = point.y - rect.Width * 3 / 4;
}

void Game::DrawGameScene(Gdiplus::Graphics& canvas) const {
	for (int i = 0; i < 7; i++) {
		tablePiles[i].DrawPiles(canvas);
	}
	for (int i = 0; i < 4; i++) {
		suitPiles[i].DrawPiles(canvas);
	}
	deckPiles.DrawPiles(canvas);
	discardPiles.DrawPiles(canvas);
	mousePiles.DrawPiles(canvas);
}