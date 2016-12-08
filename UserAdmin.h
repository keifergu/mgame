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

	bool checkNewRecorder(int type, int score, string name); // 传入一个分数，检查是否是新记录，是的话就储存，否的话返回false

	vector<string> getRankList(int n); // 获得前n的用户的排名

	vector<int> getScoreList(int type);
	vector<string> getNameList(int type);


private:
	vector<User*> userList;

	int scoreListMaxLength;
	vector<int> simpleScore;
	vector<string> simpleName;
	vector<int> middleScore;
	vector<string> middleName;
	vector<int> diffculeScore;
	vector<string> diffculeName;

	bool check(vector<int> scoreList, int score, string name);  // 传入需要比较的分数列表和分数
};

