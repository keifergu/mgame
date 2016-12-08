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

	bool checkNewRecorder(int type, int score, string name); // ����һ������������Ƿ����¼�¼���ǵĻ��ʹ��棬��Ļ�����false

	vector<string> getRankList(int n); // ���ǰn���û�������

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

	bool check(vector<int> scoreList, int score, string name);  // ������Ҫ�Ƚϵķ����б�ͷ���
};

