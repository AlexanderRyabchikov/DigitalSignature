#include "CallBackFuctionUI.h"

HINSTANCE g_hInstance;
HWND g_hEditInput;
HWND g_hEditOutput;

static const CHAR* g_pListGost[NUMBER_GOST_ALGORITM] = {
	"√Œ—“ – 34.10-94;",
	"√Œ—“ – 34.10-2001;",
	"√Œ—“ – 34.10-2012;",
	"√Œ—“ – 34.11-94;",
	"√Œ—“ – 34.11-2012" };

unsigned int GetSelectElementComboBox(HWND hWnd, int ID)
{
	HWND hComboBox = GetDlgItem(hWnd, ID);
	return SendMessage(hComboBox, CB_GETCURSEL, 0, 0);
}

void CompareGost(HWND hWnd)
{
	char* pMessageGost1 = new char[CHAR_MAX];
	char* pMessageGost2 = new char[CHAR_MAX];
	char* pResult = new char[CHAR_MAX];
	double unResultTimeFirstAlgoritm = 0, unResultTimeSecondAlgoritm = 0;
	double unStartTime, unEndTime;
	
	SendMessage(g_hEditInput, WM_GETTEXT, (WPARAM)CHAR_MAX, (LPARAM)pMessageGost1);
	memcpy(pMessageGost2, pMessageGost1, sizeof(pMessageGost1));

	unsigned int PositionCombo1 = GetSelectElementComboBox(hWnd, IDC_COMBO1);
	unsigned int PositionCombo2 = GetSelectElementComboBox(hWnd, IDC_COMBO2);

	unStartTime = clock() / 1000.0;
	GostHandler(pMessageGost1, (ListGostAlgoritm)PositionCombo1);
	unEndTime = clock() / 1000.0;

	unResultTimeFirstAlgoritm = unEndTime - unStartTime;

	unStartTime = clock() / 1000.0;
	GostHandler(pMessageGost2, (ListGostAlgoritm)PositionCombo2);
	unEndTime = clock() / 1000.0;

	unResultTimeSecondAlgoritm = unEndTime - unStartTime;

	snprintf(pResult, CHAR_MAX, "Algorithm %s time %0.4lf | Algorithm %s time %0.4lf", 
		g_pListGost[PositionCombo1], unResultTimeFirstAlgoritm, g_pListGost[PositionCombo2], unResultTimeSecondAlgoritm);

	SendMessage(g_hEditOutput, WM_SETTEXT, 0, (LPARAM)pResult);

	delete pMessageGost1, pMessageGost2, pResult;
}

void GenerateGost(HWND hWnd)
{	
	char* pMessage = new char[CHAR_MAX];
	SendMessage(g_hEditInput, WM_GETTEXT, (WPARAM)CHAR_MAX, (LPARAM)pMessage);
	unsigned int ListGenerateCombo = GetSelectElementComboBox(hWnd, IDC_COMBO_GENERATE);
	if (GostHandler(pMessage, (ListGostAlgoritm)ListGenerateCombo))
	{
		SendMessage(g_hEditOutput, WM_SETTEXT, 0, (LPARAM)pMessage);
	}
	delete pMessage;
}

void InitTexBoxGenerateDlg(HWND hWnd)
{
	g_hEditInput = GetDlgItem(hWnd, IDC_EDIT1_MESSAGE);
	g_hEditOutput = GetDlgItem(hWnd, IDC_EDIT2_KEY);
}

void InitTexBoxCompareDlg(HWND hWnd)
{
	g_hEditInput = GetDlgItem(hWnd, IDC_EDIT1);
	g_hEditOutput = GetDlgItem(hWnd, IDC_EDIT2);
}

void InitComboBox(HWND hWnd, UINT unIdComboBox)
{
	HWND hCombo = GetDlgItem(hWnd, unIdComboBox);

	for (int i = 0; i < NUMBER_GOST_ALGORITM; i++)
	{
		SendMessage(hCombo, CB_ADDSTRING, NULL, (LPARAM)g_pListGost[i]);
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
		CompareGost(hWnd);
		break;
	case IDC_BUTTON_GENERATE_KEY:
		GenerateGost(hWnd);
		break;
	case IDC_COMBO_GENERATE:
		SetDlgItemText(hWnd, IDC_EDIT1_MESSAGE, "");
		SetDlgItemText(hWnd, IDC_EDIT2_KEY, "");
		break;
	case (IDC_COMBO1 || IDC_COMBO2):
		SetDlgItemText(hWnd, IDC_EDIT1, "");
		SetDlgItemText(hWnd, IDC_EDIT2, "");
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
			InitTexBoxGenerateDlg(hWnd);
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
		InitTexBoxCompareDlg(hWnd);
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