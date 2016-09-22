#include "CallBackFuctionUI.h"

string ConversionBstrToString(BSTR bstr)
{
	USES_CONVERSION;
	string Key(W2A(bstr));
	return Key;
}

void Gost_34_10_94(char* pszMessage)
{
	string Buffer;
	IGOSTLIB34_10_94Ptr pGost(__uuidof(GostLib34_10_94));
	BSTR Result;
	BSTR MessageBuffer;
	MessageBuffer = _com_util::ConvertStringToBSTR(pszMessage);

	pGost->ReturnResultGost_34_10_94(MessageBuffer, &Result);
	Buffer = ConversionBstrToString(Result);
	strcpy(pszMessage, Buffer.c_str());
}

void Gost_34_10_2001_Func(char* pszMessage)
{
	string Buffer;
	IGOST_34_10_2001Ptr pGost(__uuidof(SharpLib94));
	BSTR Result;
	BSTR MessageBuffer;
	MessageBuffer = _com_util::ConvertStringToBSTR(pszMessage);

	pGost->MainGostLib_34(MessageBuffer, &Result);
	Buffer = ConversionBstrToString(Result);
	strcpy(pszMessage, Buffer.c_str());
}

void Gost_34_10_2012(char* pszMessage)
{
	string Buffer;
	IGostAlgoritmPtr pGost(__uuidof(SharpLib));
	BSTR Result;
	BSTR MessageBuffer;
	MessageBuffer = _com_util::ConvertStringToBSTR(pszMessage);
	
	pGost->MainGostLib(MessageBuffer, &Result);
	Buffer = ConversionBstrToString(Result);
	memset(pszMessage, 0, strlen(pszMessage));
	strcpy(pszMessage, Buffer.c_str());
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