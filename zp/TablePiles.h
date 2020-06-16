#pragma once
#include "DrawablePiles.h"
#include "OperablePiles.h"
#include "MovablePiles.h"
#include "TempPiles.h"

/// 位于桌面上的纸牌堆，主要游戏区域
class TablePiles : public DrawablePiles, public OperablePiles, public MovablePiles
{
public:
	TablePiles(); 

	/// 从临时纸牌堆初始化当前纸牌堆
	/// n：初始化的纸牌数量
	void InitCards(TempPiles& piles, int n);

	virtual bool CanOperate(std::vector<const Card*> cards) const override;
	virtual void Operate(std::vector<const Card*> cards) override;
	virtual void DrawPiles(Gdiplus::Graphics& canvas) const override;
	virtual std::vector<const Card*> RemoveClickCards(POINT point) override;
	virtual void CommitChange() override;

private:
	// 背面朝上的纸牌数量（暂时隐藏的纸牌）
	int hideCount;
};