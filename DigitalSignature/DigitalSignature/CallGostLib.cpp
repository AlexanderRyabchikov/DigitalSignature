#include "CallBackFuctionUI.h"

char* ConversionBstrToString(BSTR bstr)
{
	USES_CONVERSION;
	char* Key(W2A(bstr));
	return Key;
}

void Gost_34_10_94(char* pszMessage)
{
	IGOSTLIB34_10_94Ptr pGost(__uuidof(GostLib34_10_94));
	BSTR Result;
	pGost->ReturnResultGost_34_10_94((BSTR)pszMessage, &Result);
	memcpy(pszMessage, ConversionBstrToString(Result), sizeof(Result));
}

void Gost_34_10_2001_Func(char* pszMessage)
{
	IGOST_34_10_2001Ptr pGost(__uuidof(SharpLib94));
	BSTR Result;
	pGost->MainGostLib_34((BSTR)pszMessage, &Result);
	memcpy(pszMessage, ConversionBstrToString(Result), sizeof(Result));
}

void Gost_34_10_2012(char* pszMessage)
{
	IGostAlgoritmPtr pGost(__uuidof(SharpLib));
	BSTR Result;
	pGost->MainGostLib((BSTR)pszMessage, &Result);
	memcpy(pszMessage, ConversionBstrToString(Result), sizeof(Result));
}

void Gost_34_11_94(char* pszMessage)
{
	MainGost_34_11_94(pszMessage);
}

void Gost_34_11_2012(char* pszMessage)
{
	Gost_34_112012(pszMessage);
}

bool GostHandler(char* pszMessage, ListGostAlgoritm nNumberSelectGost)
{
	
	switch (nNumberSelectGost)
	{
	case GOST_34_10_94:
		Gost_34_10_94(pszMessage);
		break;
	case GOST_34_10_2001:
		Gost_34_10_2001_Func(pszMessage);
		break;
	case GOST_34_10_2012:
		Gost_34_10_2012(pszMessage);
		break;
	case GOST_34_11_94:
		Gost_34_11_94(pszMessage);
		break;
	case GOST_34_11_2012:
		Gost_34_11_2012(pszMessage);
		break;
	default:
		return false;

	}

	return true;
}