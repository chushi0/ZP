#pragma once

#include "framework.h"

/// �������exe�еģ�ȫ����Դ
namespace R {
	/// ����ͼ��
	extern HBITMAP back;
	/// ���� + ��ɫ
	extern HBITMAP heart, diamond, spade, clubs;
	/// ����ɫ
	extern HBITMAP heartOnly, diamondOnly, spadeOnly, clubsOnly;

	/// ������Դ
	void LoadResources();
}