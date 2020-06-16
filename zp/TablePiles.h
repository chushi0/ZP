#pragma once
#include "DrawablePiles.h"
#include "OperablePiles.h"
#include "MovablePiles.h"
#include "TempPiles.h"

/// λ�������ϵ�ֽ�ƶѣ���Ҫ��Ϸ����
class TablePiles : public DrawablePiles, public OperablePiles, public MovablePiles
{
public:
	TablePiles(); 

	/// ����ʱֽ�ƶѳ�ʼ����ǰֽ�ƶ�
	/// n����ʼ����ֽ������
	void InitCards(TempPiles& piles, int n);

	virtual bool CanOperate(std::vector<const Card*> cards) const override;
	virtual void Operate(std::vector<const Card*> cards) override;
	virtual void DrawPiles(Gdiplus::Graphics& canvas) const override;
	virtual std::vector<const Card*> RemoveClickCards(POINT point) override;
	virtual void CommitChange() override;

private:
	// ���泯�ϵ�ֽ����������ʱ���ص�ֽ�ƣ�
	int hideCount;
};