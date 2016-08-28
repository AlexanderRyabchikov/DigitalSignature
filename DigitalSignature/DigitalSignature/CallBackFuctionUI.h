#pragma once
#pragma once

#include <windows.h>
#include "resource.h"
#include <atlconv.h>

#include "Lib34_11_94\mainGost34_11_94.h"
#include "Lib34_11_2012\MainStribog.h"

#import "Lib34_10_94\Gost34_10_94Lib.tlb" raw_interfaces_only
#import "Lib34_10_2001\Gost_34_10_2001.tlb" raw_interfaces_only
#import "Lib34_10_2012\SharpLibGost.tlb" raw_interfaces_only
using namespace SharpLibGost;
using namespace Gost_34_10_2001;
using namespace Gost34_10_94Lib;

#define NUMBER_GOST_ALGORITM 5

typedef enum LIST_GOST_ALGORITM
{
	GOST_34_10_94,
	GOST_34_10_2001,
	GOST_34_10_2012,
	GOST_34_11_94,
	GOST_34_11_2012

}ListGostAlgoritm;

BOOL CALLBACK MainDlgProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK GenerateDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK CompareDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

bool GostHandler(char* pszMessage, ListGostAlgoritm nNumberSelectGost);