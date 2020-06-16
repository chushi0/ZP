#include "ResourcesBundle.h"

namespace R {
	HBITMAP back;
	HBITMAP heart, diamond, spade, clubs;
	HBITMAP heartOnly, diamondOnly, spadeOnly, clubsOnly;

	void LoadResources() {
		back = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BACK));
		heart = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_HEART));
		diamond = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_DIAMOND));
		spade = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_SPADE));
		clubs = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_CLUBS));
		heartOnly = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_HEART_ONLY));
		diamondOnly = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_DIAMOND_ONLY));
		spadeOnly = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_SPADE_ONLY));
		clubsOnly = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_CLUBS_ONLY));
	}
}