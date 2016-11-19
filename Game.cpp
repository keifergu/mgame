#include "stdafx.h"
#include "Game.h"


Game::Game()
{
	score = 0;
	allScore = 0;
	stringLength = 0;
}


Game::~Game()
{
}

int Game::getScore()
{
	return score;
}

void Game::setScore(int s)
{
	score = s;
}

void Game::addAllScore()
{
	allScore += score;
}

int Game::getStringLength()
{
	return stringLength;
}

void Game::setStringLength(int l)
{
	stringLength = l;
}


string Game::getContent()
{
	return string();
}
