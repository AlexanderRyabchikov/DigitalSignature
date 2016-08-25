#include "CallBackFuctionUI.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (MainDlgProc), 0);
	return 0;
}
