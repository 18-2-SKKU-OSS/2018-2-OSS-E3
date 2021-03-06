// KiwiCTester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../KiwiC/KiwiC.h"
#include <windows.h>
#include <locale.h>

int main()
{
	system("chcp 65001");
	_wsetlocale(LC_ALL, L"korean");
	PKIWI kw = kiwi_init("../ModelGenerator/", -1);
	kiwi_prepare(kw);
	PKIWIRESULT kr = kiwi_analyzeW(kw, (const kchar16_t*)L"1:1 한처음에 하느님께서 하늘과 땅을 창조하셨다. ", 1);
	kiwiResult_close(kr);
	kr = kiwi_analyzeW(kw, (const kchar16_t*)L"1:3 하느님께서 말씀하시기를 “빛이 생겨라.” 하시자 빛이 생겼다. ", 1);
	kiwiResult_close(kr);
	kr = kiwi_analyzeW(kw, (const kchar16_t*)L"1:3 하느님께서 말씀하시기를 “빛이 생겨라.” 하시자 빛이 생겼다. ", 1);
	int size = kiwiResult_getSize(kr);
	for (int i = 0; i < size; i++)
	{
		printf("%g\t", kiwiResult_getProb(kr, i));
		int num = kiwiResult_getWordNum(kr, i);
		for (int j = 0; j < num; j++)
		{
			wprintf(L"%s/%s(%d~%d)\t", kiwiResult_getWordFormW(kr, i, j), kiwiResult_getWordTagW(kr, i, j), 
				kiwiResult_getWordPosition(kr, i, j), kiwiResult_getWordPosition(kr, i, j) + kiwiResult_getWordLength(kr, i, j));
		}
		printf("\n");
	}
	kiwiResult_close(kr);
	kiwi_close(kw);
	getchar();
    return 0;
}

