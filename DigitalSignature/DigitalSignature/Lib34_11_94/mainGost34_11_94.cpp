#include "gost.h"
#include "mainGost34_11_94.h"

void MainGost_34_11_94(char* pMessage)
{
	gost(pMessage, sizeof(pMessage));
}
