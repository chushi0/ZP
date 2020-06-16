#pragma once
#include "DrawablePiles.h"
#include "MovablePiles.h"
#include "OperablePiles.h"

// ��������ֽ�ƶѣ������ֱ�ӿ���
class MousePiles : public DrawablePiles
{
public:
	MousePiles();

	/// ���Դ�ָ��ֽ�ƶѻ�ȡֽ��
	/// ����ɹ���ȡ���򷵻� true�����򷵻� false
	bool GetCardsFromPiles(MovablePiles* piles, POINT point);
	/// ���Խ�ֽ�Ʒ���ֽ�ƶ�
	/// ����ɹ����򷵻� true
	/// ���ʧ�ܣ���ֽ�ƶѷŻ���Դֽ�ƶѣ������� false
	/// �����Դ��Ŀ����ͬ������Ϊʧ��
	/// ���Ŀ�����Ϊ�գ�����Ϊʧ��
	bool PutCardsToPiles(OperablePiles* piles);

	virtual void DrawPiles(Gdiplus::Graphics& canvas) const override;

private:
	/// ��¼��ǰ���е�ֽ����Դ
	MovablePiles* fromPiles;
};

