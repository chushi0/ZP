#pragma once
#include "DrawablePiles.h"
#include "MovablePiles.h"

/// ÆúÅÆÇøÖ½ÅÆ¶Ñ
class DiscardPiles : public DrawablePiles, public MovablePiles
{
public:

	/// ¼ÓÈëÆúÅÆ¶Ñ
	void PushCard(const Card* card);
	/// µ¹Ğò·µ»ØÆúÅÆ¶Ñ
	std::vector<const Card*> PopCards();

	virtual void DrawPiles(Gdiplus::Graphics& canvas) const override;
	virtual std::vector<const Card*> RemoveClickCards(POINT point) override;
};

