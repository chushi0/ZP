#pragma once
#include "framework.h"

/// ֽ��
class Card
{
public:
	/// ��ɫ������Ϊ ���ҡ���Ƭ�����ҡ�÷��
	enum Decor { Heart, Diamond, Spade, Clubs };
	/// ��ɫ������Ϊ ��ɫ����ɫ
	enum Color { Red, Black };

	/// ���ݻ�ɫ�͵���������Ӧֽ��
	Card(Decor decor, int point);

	/// ��ȡֽ�ƻ�ɫ
	Decor GetDecor() const;
	/// ��ȡֽ����ɫ
	Color GetColor() const;
	/// ��ȡֽ�Ƶ���
	int GetPoint() const;

	/// ��ָ�������ڻ���
	/// face: true - ��������  false - ���Ʊ���
	/// ���������߱�ӦΪ 2:3
	void Draw(Gdiplus::Graphics& canvas, bool face, Gdiplus::RectF rect) const;

	// ��ֹ����
	Card(const Card&) = delete;
	Card operator=(const Card&) = delete;

private:
	/// ��ɫ
	Decor decor;
	/// ����
	int point;
};

inline Card::Decor Card::GetDecor() const {
	return decor;
}

inline Card::Color Card::GetColor() const {
	return decor <= Diamond ? Red : Black;
}

inline int Card::GetPoint() const {
	return point;
}