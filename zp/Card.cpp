#include "Card.h"
#include <string>

Card::Card(Decor decor, int point) :
	decor(decor), point(point) {
	assert(decor >= 0 && decor < 4);
	assert(point >= 1 && point <= 13);
}

void Card::Draw(Gdiplus::Graphics& canvas, bool face, Gdiplus::RectF rect) const {
	if (face) {
		// 绘制卡面图案
		HBITMAP hBmp[] = { R::heart, R::diamond, R::spade, R::clubs };
		Gdiplus::Bitmap bmp(hBmp[decor], NULL);
		canvas.DrawImage(&bmp, rect);
		Gdiplus::Bitmap tempBmp(200, 300);
		Gdiplus::Graphics* temp = Gdiplus::Graphics::FromImage(&tempBmp);
		Gdiplus::Font font(L"Times New Roman", 20);
		Gdiplus::SolidBrush redBrush({ 255, 0, 0 }), blackBrush({ 0, 0, 0 });
		Gdiplus::SolidBrush* brush;
		if (GetColor() == Red) brush = &redBrush;
		else brush = &blackBrush;
		static std::wstring str[] = { L"A", L"2",L"3",L"4",L"5",L"6",L"7",L"8",L"9",L"10",L"J",L"Q",L"K" };
		temp->DrawString(str[GetPoint() - 1].c_str(), str[GetPoint() - 1].size(), &font, Gdiplus::PointF(35, 5), brush);
		canvas.DrawImage(&tempBmp, rect);
		delete temp;
	} else {
		// 绘制卡背
		Gdiplus::Bitmap bmp(R::back, NULL);
		canvas.DrawImage(&bmp, rect);
	}
}