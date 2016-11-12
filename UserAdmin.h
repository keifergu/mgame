#pragma once
#include"User.h"
#include<vector>
#include<string>

using namespace std;
class UserAdmin
{
public:
	UserAdmin();
	~UserAdmin();

	void reg(string username, string password);
	bool login(string username, string password);

	vector<string> getRankList(int n); // 获得前n的用户的排名
private:
	vector<User*> userList;
};

