#include "stdafx.h"
#include "MiddleGame.h"


MiddleGame::MiddleGame()
{
	setStringLength(4);
	setScore(2);
}


MiddleGame::~MiddleGame()
{
}

string MiddleGame::getContent()
{
	std::random_device rd;
	char* word = "0123456789abcdefghijklmnopqrstuvwxyz";
	string content;
	for (int n = 0; n < getStringLength(); ++n) {
		content.push_back(word[rd() % 36]);
	}
	return string(content);
}
