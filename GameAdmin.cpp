#include "stdafx.h"
#include "GameAdmin.h"


GameAdmin::GameAdmin()
{
}


GameAdmin::~GameAdmin()
{
}

void GameAdmin::setGameDegress(string tdegress)
{
	degress = tdegress[0];
	switch (tdegress[0])
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
		degress = "0";
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

vector<string> GameAdmin::getGameInfo()
{
	int points = getTotalPoints();
	char buf[10];
	sprintf(buf, "%d", points);
	string point = buf;
	vector<string> info{ degress, point};
	return vector<string>({ degress, point });
}

void GameAdmin::reset()
{
	delete game;
	degress = "0";
	gameContent.clear();
	answer.clear();
	points.clear();
}
