#pragma once
#include "OperablePiles.h"
#include "DrawablePiles.h"
#include "MovablePiles.h"

/// �Ѿ������ֽ�ƶ�
class SuitPiles : public OperablePiles, public DrawablePiles, public MovablePiles
{
public:
	/// ȷ����ֽ�ƶ���Ҫ����Ļ�ɫ
	SuitPiles(Card::Decor decor);

	/// �жϵ�ǰֽ�ƶ��Ƿ�����
	/// ����������ʾ�Ѿ��޷��ټ����µ�ֽ��
	/// �����е� SuitPiles ��ʱ������Ϊ��Ϸ����
	bool Full() const;

	virtual bool CanOperate(std::vector<const Card*> cards) const override;
	virtual void Operate(std::vector<const Card*> cards) override;
	virtual void DrawPiles(Gdiplus::Graphics& canvas) const override;
	virtual std::vector<const Card*> RemoveClickCards(POINT point) override;

private:
	/// ֽ�ƶ���Ҫ����Ļ�ɫ
	const Card::Decor decor;
};

inline bool SuitPiles::Full() const {
	return cards.size() == 13;
}