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
			if (userList[i]->login(password)) {
				userId = i;
				return true;
			}
		}
	}
	return false;
}

bool UserAdmin::checkNewRecorder(int type, int score)
{
	bool result;
	switch (type)
	{
	case 1:
		result = check(simpleScore, score);
		break;
	case 2:
		result = check(middleScore, score);
		break;
	case 3:
		result = check(diffculeScore, score);
		break;
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
	case 1:
		return simpleScore;
	case 2:
		return middleScore;
	case 3:
		return diffculeScore;
	default:
		return simpleScore;
		break;
	}
}

vector<string> UserAdmin::getNameList(int type)
{
	switch (type)
	{
	case 1:
		return simpleName;
	case 2:
		return middleName;
	case 3:
		return diffculeName;
	default:
		break;
	}
}

bool UserAdmin::check(vector<int> &scoreList, int score)
{
	if (score == 0) return false;
	int length = scoreList.size();
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
