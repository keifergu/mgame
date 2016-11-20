#pragma once
#include"stdafx.h"
#include<string>
#include<map>
#include<iostream>
using namespace std;

class App
{
public:
	App();
	~App();

	void run();
	void viewStartMenu();
	void viewRegister();
	void viewLogin();
	void viewUserMenu();
	void viewRankAdmin();
	void viewRankList(string degree);
	void viewGameAdmin();
	void viewGamePlay(string degree);

	void viewGameEnd(string degress);

	void countdown(int time);
private:
	UserAdmin* userAdmin;
	GameAdmin* gameAdmin;
};

