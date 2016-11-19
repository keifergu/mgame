#include "stdafx.h"
#include "App.h"


App::App()
{
	userAdmin = new UserAdmin();
	run();
}


App::~App()
{
}

void App::run()
{
	viewStartMenu();
}

void App::viewStartMenu()
{
	char choose;
	cout << "-----欢迎来到记忆游戏-----" << endl;
	cout << "1.登录账号进行游戏" << endl;
	cout << "2.注册账号" << endl;
	cout << "请选择:";
	cin >> choose;
	if (choose == '1') viewLogin();
	else if (choose == '2') viewRegister();
	else exit(0);
}

void App::viewRegister()
{
	string username, password;
	cout << "请输入用户名：";
	cin >> username;
	cout << "请输入密码：";
	cin >> password;
	userAdmin->reg(username, password);
	viewStartMenu();
}

void App::viewLogin()
{
	string username, password;
	cout << "请输入用户名：";
	cin >> username;
	cout << "请输入密码：";
	cin >> password;
	bool res;
	res = userAdmin->login(username, password);
	if (res)
	{
		viewUserMenu();
	}
	else
	{
		cout << "登录失败，请重新输入!" << endl;
		viewLogin();
	}
}

void App::viewUserMenu()
{
	char choose;
	cout << "-----欢迎来到记忆游戏-----" << endl;
	cout << "1.开始游戏" << endl;
	cout << "2.分数排名" << endl;
	cout << "请选择:";
	cin >> choose;
	if (choose == '1') viewLogin();
	else if (choose == '2') viewRegister();
	else exit(0);
}

void App::viewRankAdmin()
{
	string choose;
	cout << "-----分数排名-----" << endl;
	cout << "1.简单" << endl;
	cout << "2.一般" << endl;
	cout << "3.困难" << endl;
	cout << "请选择查看排名的难度:";
	cin >> choose;
	if (choose == "1") viewRankList(choose);
	else if (choose == "2") viewRankList(choose);
	else if (choose == "3") viewRankList(choose);
	else if (choose == "0") viewUserMenu();
	else {
		cout << "难度不存在，请重新选择!";
		viewRankAdmin();
	}
}

void App::viewRankList(string type)
{
}

void App::viewGameAdmin()
{
	string choose;
	cout << "-----游戏难度选择-----" << endl;
	cout << "1.简单" << endl;
	cout << "2.一般" << endl;
	cout << "3.困难" << endl;
	cout << "请选择游戏的难度:";
	cin >> choose;
	if (choose == "1") viewGamePlay(choose);
	else if (choose == "2") viewGamePlay(choose);
	else if (choose == "3") viewGamePlay(choose);
	else if (choose == "0") viewUserMenu();
	else {
		cout << "难度不存在，请重新选择!";
		viewRankAdmin();
	}
}

void App::viewGamePlay(string degree)
{
}
