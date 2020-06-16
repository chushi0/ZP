#pragma once
#include "DrawablePiles.h"
#include "MovablePiles.h"

/// ������ֽ�ƶ�
class DiscardPiles : public DrawablePiles, public MovablePiles
{
public:

	/// �������ƶ�
	void PushCard(const Card* card);
	/// ���򷵻����ƶ�
	std::vector<const Card*> PopCards();

	virtual void DrawPiles(Gdiplus::Graphics& canvas) const override;
	virtual std::vector<const Card*> RemoveClickCards(POINT point) override;
};

