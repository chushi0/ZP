#pragma once
#include "framework.h"

/// 纸牌
class Card
{
public:
	/// 花色，依次为 红桃、方片、黑桃、梅花
	enum Decor { Heart, Diamond, Spade, Clubs };
	/// 颜色，依次为 红色、黑色
	enum Color { Red, Black };

	/// 依据花色和点数创建对应纸牌
	Card(Decor decor, int point);

	/// 获取纸牌花色
	Decor GetDecor() const;
	/// 获取纸牌颜色
	Color GetColor() const;
	/// 获取纸牌点数
	int GetPoint() const;

	/// 在指定区域内绘制
	/// face: true - 绘制正面  false - 绘制背面
	/// 矩形区域宽高比应为 2:3
	void Draw(Gdiplus::Graphics& canvas, bool face, Gdiplus::RectF rect) const;

	// 禁止复制
	Card(const Card&) = delete;
	Card operator=(const Card&) = delete;

private:
	/// 花色
	Decor decor;
	/// 点数
	int point;
};

inline Card::Decor Card::GetDecor() const {
	return decor;
}

inline Card::Color Card::GetColor() const {
	return decor <= Diamond ? Red : Black;
}

inline int Card::GetPoint() const {
	return point;
}