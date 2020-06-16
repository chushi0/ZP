// header.h: 标准系统包含文件的包含文件，
// 或特定于项目的包含文件
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
// Windows 头文件
#include <windows.h>
#include <comdef.h>
#include <gdiplus.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// 资源文件
#include "Resource.h"
#include "ResourcesBundle.h"

// 调试
#if !defined(_DEBUG) && !defined(NDEBUG)
#define NDEBUG
#endif
#include <assert.h>

// 全局变量
extern HINSTANCE hInstance;
extern HINSTANCE hPrevInstance;
extern LPWSTR lpCmdLine;
extern int nCmdShow;