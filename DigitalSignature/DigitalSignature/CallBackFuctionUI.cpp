#include "CallBackFuctionUI.h"

BOOL CALLBACK MainDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		break;
	case WM_COMMAND:
		break;
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return FALSE;
		break;
	default:
		break;
	}
	return FALSE;
}