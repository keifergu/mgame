#pragma once
#include"stdafx.h"
class GameAdmin
{
public:
	GameAdmin();
	~GameAdmin();
	
	void setGameDegress(string degress);
	string getContent();
	bool checkAnswer(string userAnswer);
	int getTotalPoints();

private:
	Game* game;
	vector<string> *gameContent;
	vector<string> *answer;
	vector<int> points;
};

