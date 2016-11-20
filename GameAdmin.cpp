#include "stdafx.h"
#include "GameAdmin.h"


GameAdmin::GameAdmin()
{
}


GameAdmin::~GameAdmin()
{
}

void GameAdmin::setGameDegress(string degress)
{
	switch (degress[0])
	{
	case('1') :
		game = new SimpleGame();
		break;
	case('2') :
		game = new MiddleGame();
		break;
	case('3') :
		game = new DiffcultGame();
		break;
	default:
		break;
	}
}

string GameAdmin::getContent()
{
	string content = game->getContent();
	gameContent.push_back(content);
	return string(content);
}

bool GameAdmin::checkAnswer(string userAnswer)
{
	answer.push_back(userAnswer);
	if (gameContent.back() == userAnswer) {
		points.push_back(game->getScore());
		return true;
	}
	else {
		points.push_back(0);
		return false;
	};
}

int GameAdmin::getTotalPoints()
{
	int total = 0;
	for (int i = 0; i < points.size(); i++)
	{
		total += points[i];
	}
	return 0;
}
