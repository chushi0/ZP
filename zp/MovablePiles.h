#pragma once
#include "CardPiles.h"

/// ��ͨ����Ҳ���������ֽ���ƶ��������ֽ�ƶѵ�ֽ�ƶ�
/// ͨ�����ԣ�������Ҫ MousePiles ��Ϊ��ת���� MousePiles ���̳д���
class MovablePiles : virtual public CardPiles
{
public:
	/// �����������λ�ã�������Ϸ�����Ƴ�������ֽ��
	/// �����������Ϸ�����򲻷����κ�ֽ��
	virtual std::vector<const Card*> RemoveClickCards(POINT point) = 0;

	/// �ύ���ģ�֮ǰ�Ƴ���ֽ�ƶ��Ѿ����뵽������ƶ�
	/// �˺��������ƶ�ֽ�ƺ�Ժ�����Ϊ���м��
	/// Ĭ������£��ú���û��ʵ��
	virtual void CommitChange();

	/// ���Ѿ��Ƴ���ֽ�ƶѸ�ԭ
	/// �ú��������û������ƶ�����ֽ�Ƶ�ʧ�ܺ����
	void RestoreChange(std::vector<const Card*> cards);
};

