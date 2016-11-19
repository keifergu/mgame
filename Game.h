#pragma once
#include<string>
#include<random>
using namespace std;

class Game
{
public:
	Game();
	~Game();

	int getScore();
	void setScore(int s);
	void addAllScore();
	int getStringLength();
	void setStringLength(int l);
	virtual string getContent();

private:
	int score;
	int allScore;
	int stringLength;
	string degree;
};

