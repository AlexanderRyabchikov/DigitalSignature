#pragma once
#include <windows.h>
#include "resource.h"

#define NUMBER_GOST_ALGORITM 5

BOOL CALLBACK MainDlgProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK GenerateDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK CompareDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);