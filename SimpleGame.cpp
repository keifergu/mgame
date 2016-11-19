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
	string content;
	for (int n = 0; n < getStringLength(); ++n)
		content[n] = rd() % 10;
	return string(content);
}
