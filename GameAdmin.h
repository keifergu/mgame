#pragma once
#include"stdafx.h"
class GameAdmin
{
public:
	GameAdmin();
	~GameAdmin();
	
	void setGameDegress(string degress); // ������Ϸ���Ѷȵȼ�
	string getContent();				 // �����Ϸ���ַ�����ÿ�ε��ý������ͬ
	bool checkAnswer(string userAnswer); // ���ÿһ�εĴ��Ƿ���ȷ
	int getTotalPoints();				 // ����ܷ�
	vector<string> getGameInfo();		 // �����Ϸ����Ϣ
	void reset();						 // ������Ϸ

private:
	Game *game;					 // Game���࣬������Ų�ͬ�Ѷȵ���Ϸ��
	string degress;				 // �Ѷ�
	vector<string> gameContent;  // ����ô���Ϸ��������Ŀ
	vector<string> answer;		 // ����ô���Ϸ�����д�
	vector<int> points;			 // ����ô���Ϸ�����е÷�
};

