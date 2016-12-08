#pragma once
#include"stdafx.h"
class GameAdmin
{
public:
	GameAdmin();
	~GameAdmin();
	
	void setGameDegress(string degress); // 设置游戏的难度等级
	string getContent();				 // 获得游戏的字符串，每次调用结果都不同
	bool checkAnswer(string userAnswer); // 检查每一次的答案是否正确
	int getTotalPoints();				 // 获得总分
	vector<string> getGameInfo();		 // 获得游戏的信息
	void reset();						 // 重置游戏

private:
	Game *game;					 // Game基类，用来存放不同难度的游戏类
	string degress;				 // 难度
	vector<string> gameContent;  // 储存该次游戏的所有题目
	vector<string> answer;		 // 储存该次游戏的所有答案
	vector<int> points;			 // 储存该次游戏的所有得分
};

