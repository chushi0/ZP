#pragma once
#include "CardPiles.h"

/// 可绘制的纸牌堆
/// 标记当前纸牌堆可以绘制
class DrawablePiles : virtual public CardPiles
{
public:
	DrawablePiles();

	/// 绘制纸牌堆
	virtual void DrawPiles(Gdiplus::Graphics& canvas) const = 0;

	/// 设置或获取纸牌堆（在屏幕上的）位置
	Gdiplus::RectF& Rect();
	/// const 版本
	const Gdiplus::RectF& Rect() const;
	/// 判断（屏幕上的）指定点是否位于所显示的区域内
	bool RectContains(Gdiplus::PointF point) const;

protected:
	/// 纸牌堆（在屏幕上的）位置
	Gdiplus::RectF rectPosition;
};


inline Gdiplus::RectF& DrawablePiles::Rect() {
	return rectPosition;
}

inline const Gdiplus::RectF& DrawablePiles::Rect() const {
	return rectPosition;
}

inline bool DrawablePiles::RectContains(Gdiplus::PointF point) const {
	return rectPosition.Contains(point);
}