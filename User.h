#pragma once
#include<vector>
#include<string>
#include<map>

using namespace std;

class User
{
public:
	User(string username, string password);
	~User();

	string getName();
	int getHighestScore(string type);
	bool login(string passWord);


private:
	string _username;
	string _password;
};

