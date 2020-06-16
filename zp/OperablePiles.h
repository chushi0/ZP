#pragma once
#include "CardPiles.h"

/// ��ͨ����Ҳ��������м���ֽ�Ƶ�ֽ�ƶ�
/// ����ֽ�ƶ�ǰӦ���ж��Ƿ���Լ��룬Ȼ���ٵ��ü���ֽ�ƶѵķ���
/// ͨ�����ԣ�������Ҫ MousePiles ��Ϊ��ת���� MousePiles ���̳д���
class OperablePiles : virtual public CardPiles
{
public:

	/// �ж��Ƿ���Խ�������ֽ�ƶѼ��뵽��ǰֽ�ƶ�
	virtual bool CanOperate(std::vector<const Card*> cards) const = 0;

	/// ��������ֽ�ƶѼ��뵽��ǰֽ�ƶ�
	virtual void Operate(std::vector<const Card*> cards) = 0;
};
