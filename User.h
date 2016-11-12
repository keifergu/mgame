#pragma once
#include<vector>
#include<string>

using namespace std;

class User
{
public:
	User(string username, string password);
	~User();

	string getName();
	int getHighestScore();
	bool login(string passWord);
	vector<int> getScoreList();

private:
	string _username;
	string _password;
	vector<int> scoreList;
};

