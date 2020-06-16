#pragma once
#include "framework.h"
#include "Card.h"
#include <vector>

/// ֽ�ƶ�
class CardPiles
{
public:
	CardPiles();
	virtual ~CardPiles() = default;

	/// �Ƿ��Ѿ�û���κ�ֽ��
	bool Empty() const;
	/// ��ȡֽ������
	int Count() const;
	
	/// ���ֽ�ƶ�����ֽ��
	/// ע�⣺�� TempPiles ���ô˺��������ܻ�����ڴ�й¶
	void Clear();

	// ��ֹ����
	CardPiles(const CardPiles&) = delete;
	CardPiles operator=(const CardPiles&) = delete;

protected:
	/// ��ȡ����ֽ�ƣ�ֽ�ƶ����ɱ�����ֽ�ƣ�
	const Card* GetTopCard() const;

	/// ֽ��
	std::vector<const Card*> cards;
};

inline bool CardPiles::Empty() const {
	return cards.size() == 0;
}

inline int CardPiles::Count() const {
	return cards.size();
}

inline void CardPiles::Clear() {
	cards.clear();
}