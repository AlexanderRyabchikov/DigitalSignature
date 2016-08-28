#include "CallBackFuctionUI.h"

HINSTANCE g_hInstance;
HWND g_hEditInput;
HWND g_hEditOutput;

void SelectGost(WPARAM wParam)
{	
	char* pMessage = new char[CHAR_MAX];
	SendMessage(g_hEditInput, WM_GETTEXT, (WPARAM)255, (LPARAM)pMessage);
	if (GostHandler(pMessage, (ListGostAlgoritm)CBN_SETFOCUS))
	{
		SendMessage(g_hEditOutput, WM_SETTEXT, 0, (LPARAM)pMessage);
	}
	delete pMessage;
}

void InitTexBox(HWND hWnd)
{
	g_hEditInput = GetDlgItem(hWnd, IDC_EDIT1_MESSAGE);
	g_hEditOutput = GetDlgItem(hWnd, IDC_EDIT2_KEY);
}

void InitComboBox(HWND hWnd, UINT unIdComboBox)
{
	const CHAR* pListGost[NUMBER_GOST_ALGORITM] = {
		"√Œ—“ – 34.10-94;",
		"√Œ—“ – 34.10-2001;",
		"√Œ—“ – 34.10-2012;",
		"√Œ—“ – 34.11-94;",
		"√Œ—“ – 34.11-2012"};

	HWND hCombo = GetDlgItem(hWnd, unIdComboBox);

	for (int i = 0; i < NUMBER_GOST_ALGORITM; i++)
	{
		SendMessage(hCombo, CB_ADDSTRING, NULL, (LPARAM)pListGost[i]);
	}
}

void CaseButton(WPARAM wParam, HWND hWnd)
{
	switch (LOWORD(wParam))
	{
	case IDC_BUTTON2_COMPARE:
		DialogBoxParam(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG3), NULL, (CompareDlgProc), NULL);
		break;
	case IDC_BUTTON_GENERATE:
		DialogBoxParam(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG2), NULL, (GenerateDlgProc), NULL);
		break;
	case IDC_BUTTON_COMPARE_ALGORITM:
		break;
	case IDC_BUTTON_GENERATE_KEY:
		SelectGost(wParam);
		break;
	case IDC_COMBO_GENERATE:
		SetDlgItemText(hWnd, IDC_EDIT1_MESSAGE, "");
		SetDlgItemText(hWnd, IDC_EDIT2_KEY, "");
		break;
	case IDC_BUTTON2_PREV:
			EndDialog(hWnd, 0);
		break;
	default:
		break;
	}
}


BOOL CALLBACK GenerateDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
			InitComboBox(hWnd, IDC_COMBO_GENERATE);
			InitTexBox(hWnd);
		break;
	case WM_COMMAND:
			CaseButton(wParam, hWnd);
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

BOOL CALLBACK CompareDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		InitComboBox(hWnd, IDC_COMBO1);
		InitComboBox(hWnd, IDC_COMBO2);
		InitTexBox(hWnd);
		break;
	case WM_COMMAND:
			CaseButton(wParam, hWnd);
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

BOOL CALLBACK MainDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
			g_hInstance = GetModuleHandle(NULL);
		break;
	case WM_COMMAND:
		CaseButton(wParam, hWnd);
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