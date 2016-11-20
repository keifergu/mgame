#include "stdafx.h"
#include "SimpleGame.h"
#include<random>

SimpleGame::SimpleGame()
{
	setStringLength(4);
}


SimpleGame::~SimpleGame()
{
}

string SimpleGame::getContent()
{
	std::random_device rd;
	char *num = "0123456789";
	string content;
	for (int n = 0; n < getStringLength(); ++n) {
		content.push_back(num[rd() % 10]);
	}
	return string(content);
}
