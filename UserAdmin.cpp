#include "stdafx.h"
#include "UserAdmin.h"


UserAdmin::UserAdmin()
{
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

vector<string> UserAdmin::getRankList(int n)
{
	return vector<string>();
}
