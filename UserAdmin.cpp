#include "stdafx.h"
#include "UserAdmin.h"


UserAdmin::UserAdmin()
{
	scoreListMaxLength = 5;
}


UserAdmin::~UserAdmin()
{
}

void UserAdmin::reg(string username, string password)
{
	userList.push_back(new User(username, password));
}

bool UserAdmin::login(string username, string password)
{
	int length = userList.size();
	for (int i = 0; i < length; i++)
	{
		if (username == userList[i]->getName()) {
			return userList[i]->login(password);
		}
	}
	return false;
}

bool UserAdmin::checkNewRecorder(int type, int score, string name)
{
	bool result;
	switch (type)
	{
	case 0:
		result = check(simpleScore, score, name);
	case 1:
		result = check(middleScore, score, name);
	case 2:
		result = check(diffculeScore, score, name);
	default:
		result = false;
		break;
	}

	return result;
}

vector<string> UserAdmin::getRankList(int n)
{
	return vector<string>();
}

vector<int> UserAdmin::getScoreList(int type)
{
	switch (type)
	{
	case 0:
		return simpleScore;
	case 1:
		return middleScore;
	case 2:
		return diffculeScore;
	default:
		break;
	}
}

vector<string> UserAdmin::getNameList(int type)
{
	switch (type)
	{
	case 0:
		return simpleName;
	case 1:
		return middleName;
	case 2:
		return diffculeName;
	default:
		break;
	}
}

bool UserAdmin::check(vector<int> scoreList, int score, string name)
{
	int length = scoreList.size;
	if (length < scoreListMaxLength)
	{
		scoreList.push_back(score);
		sort(scoreList.begin(), scoreList.end());
		return true;
	}
	if (scoreList.back() < score)
	{
		scoreList.pop_back();
		scoreList.push_back(score);
		sort(scoreList.begin(), scoreList.end());
		return true;
	}
	return false;
}
