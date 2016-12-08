#include "stdafx.h"
#include "DiffcultGame.h"


DiffcultGame::DiffcultGame()
{
	setScore(4);
	setStringLength(8);
}


DiffcultGame::~DiffcultGame()
{
}

string DiffcultGame::getContent()
{
	std::random_device rd;
	char* word = "0123456789abcdefghijklmnopqrstuvwxyz";
	string content;
	for (int n = 0; n < getStringLength(); ++n)
		content.push_back(word[rd() % 36]);
	return string(content);
}
