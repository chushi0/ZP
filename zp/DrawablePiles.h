#pragma once
#include "CardPiles.h"

/// �ɻ��Ƶ�ֽ�ƶ�
/// ��ǵ�ǰֽ�ƶѿ��Ի���
class DrawablePiles : virtual public CardPiles
{
public:
	DrawablePiles();

	/// ����ֽ�ƶ�
	virtual void DrawPiles(Gdiplus::Graphics& canvas) const = 0;

	/// ���û��ȡֽ�ƶѣ�����Ļ�ϵģ�λ��
	Gdiplus::RectF& Rect();
	/// const �汾
	const Gdiplus::RectF& Rect() const;
	/// �жϣ���Ļ�ϵģ�ָ�����Ƿ�λ������ʾ��������
	bool RectContains(Gdiplus::PointF point) const;

protected:
	/// ֽ�ƶѣ�����Ļ�ϵģ�λ��
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