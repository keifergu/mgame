#include "stdafx.h"
#include "User.h"


User::User(string username, string password)
	:_username(username),_password(password)
{
}


User::~User()
{
}

string User::getName()
{
	return string(_username);
}

int User::getHighestScore(string type)
{
	vector<int> typeScore = getScoreList(type);
	int length = typeScore.size();
	int max = 0;
	for (int i = 0; i < length; i++)
	{
		max = max > typeScore[i] ? max : typeScore[i];
	}
	return max;
}

bool User::login(string password)
{
	if (password == _password)
	{
		return true;
	}
	return false;
}



