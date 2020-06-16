#pragma once
#include "CardPiles.h"

/// ��ʱֽ�ƶѣ�������Ϸ��ʼʱ�������ƶѷ��ƣ���֧�ֻ�ͼ����
/// �ڷ�����ֽ�ƺ󣬸�ֽ�ƶ����ɱ���ֽ�ƶ�������ʱһ������
class TempPiles : public CardPiles
{
public:
	TempPiles();
	virtual ~TempPiles();

	/// ϴ��
	void Shuffle();

	/// ��ȡ X ��ֽ��
	/// ���ʣ��ֽ���Ѿ����㣬�򷵻�����ʣ���ֽ��
	std::vector<const Card*> GetCards(int count);
	/// ��ȡʣ��ȫ��ֽ��
	std::vector<const Card*> GetAllCards();

private:
	/// ʣ��δ�����ֽ����
	int valid;
};

inline std::vector<const Card*> TempPiles::GetAllCards() {
	return GetCards(52);
}