#pragma once
#include "Game.h"
#include<string>
using namespace std;

class SimpleGame :
	public Game
{
public:
	SimpleGame();
	~SimpleGame();

	string getContent();
};

