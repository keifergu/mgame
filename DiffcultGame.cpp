#include "stdafx.h"
#include "DiffcultGame.h"


DiffcultGame::DiffcultGame()
{
	setStringLength(4);
}


DiffcultGame::~DiffcultGame()
{
}

string DiffcultGame::getContent()
{
	std::random_device rd;
	string word = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string content;
	for (int n = 0; n < getStringLength(); ++n)
		content[n] = word[rd() % 62];
	return string(content);
}
