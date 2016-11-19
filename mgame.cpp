// mgame.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"App.h"
#include<iostream>
#include<random>
#include <windows.h>
int main()
{
//	new App();
/*	std::random_device rd;
	for (int n = 0; n<20000; ++n)
		std::cout << rd()%100 << std::endl;*/
	cout << "abcd";
	Sleep(1000);
	for (int i = 0; i < 3; i++)
	{
		cout << "\b" << i;
		Sleep(1000);
	}

	system("cls");
	Sleep(1000);
    return 0;
}

