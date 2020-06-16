#pragma once
#include "DrawablePiles.h"
#include "TempPiles.h"

/// �ƿ�����ֽ�ƶѣ������ֽ�ƽ��ƶ������ƶ�
class DeckPiles : public DrawablePiles
{
public:
	
	/// ����ʱֽ�ƶѳ�ʼ����ǰֽ�ƶ�
	/// ע�⣺�÷�������ȡ TempPiles �е�ȫ��ʣ��ֽ��
	void InitCards(TempPiles& piles);

	/// ��������ֽ��
	const Card* PopCard();
	/// ��ֽ�����°�˳�����
	void PushCards(std::vector<const Card*> cards);

	virtual void DrawPiles(Gdiplus::Graphics& canvas) const override;
};

inline void DeckPiles::InitCards(TempPiles& piles) {
	PushCards(piles.GetAllCards());
}