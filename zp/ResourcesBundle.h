#pragma once

#include "framework.h"

/// （打包在exe中的）全局资源
namespace R {
	/// 卡背图案
	extern HBITMAP back;
	/// 卡面 + 花色
	extern HBITMAP heart, diamond, spade, clubs;
	/// 仅花色
	extern HBITMAP heartOnly, diamondOnly, spadeOnly, clubsOnly;

	/// 加载资源
	void LoadResources();
}