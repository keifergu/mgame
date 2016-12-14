#include "stdafx.h"
#include "App.h"


App::App()
{
	userAdmin = new UserAdmin();
	gameAdmin = new GameAdmin();
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
	system("cls");
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
	system("cls");
	string username, password;
	cout << "-----用户注册-----" << endl;
	cout << "请输入用户名：";
	cin >> username;
	cout << "请输入密码：";
	cin >> password;
	userAdmin->reg(username, password);
	viewStartMenu();
}

void App::viewLogin()
{
	system("cls");
	cout << "-----用户登录-----" << endl;
	string username, password;
	cout << "请输入用户名：";
	cin >> username;
	cout << "请输入密码：";
	cin >> password;
	bool res;
	res = userAdmin->login(username, password);
	if (res)
	{
		cout << "登录成功！" << endl;
		Sleep(1000);
		viewUserMenu();
	}
	else
	{
		cout << "登录失败，请重新登录!" << endl;
		Sleep(1500);
		viewLogin();
	}
}

void App::viewUserMenu()
{
	system("cls");
	char choose;
	cout << "-----欢迎来到记忆游戏-----" << endl;
	cout << "1.开始游戏" << endl;
	cout << "2.分数排名" << endl;
	cout << "3.退出游戏" << endl;
	cout << "请选择:";
	cin >> choose;
	if (choose == '1') viewGameAdmin();
	else if (choose == '2') viewRankAdmin();
	else exit(0);
}

void App::viewRankAdmin()
{
	system("cls");
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
	system("cls");
	vector<int> scoreList;
	scoreList = userAdmin->getScoreList(atoi(type.c_str()));
	cout << "分数排行耪：" << endl;
	for (int i = 0; i < scoreList.size(); i++)
	{
		cout << "第" << i + 1 << "名：" << scoreList[i] << endl;
	}
	cout << "\n1.查看其他排名\n2.返回主菜单\n请选择：";
	char i = '0';
	cin >> i;
	if (i == '1') viewRankAdmin();
	else if (i == '2') viewUserMenu();
}

void App::viewGameAdmin()
{
	system("cls");
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
		viewGameAdmin();
	}
}

void App::countdown(int time) {
	cout << time;
	Sleep(1000);
	for (int i = time - 1; i > 0; i--)
	{
		cout << "\b" << i;
		Sleep(1000);
	}
}

void App::viewGamePlay(string degress)
{
	system("cls");
	char tmp;
	cout << "游戏马上开始，您有5秒钟的时间去记忆屏幕上出现的字符串，然后写下它" << endl;
	cout << "------输入任意字符开始游戏------" << endl;
	cin >> tmp;
	system("cls");
	string userAnswer;
	gameAdmin->setGameDegress(degress);
	for (int i = 0; i < 1; i++)
	{
		cout << "------记忆小游戏------(分数：" << gameAdmin->getTotalPoints() << "分)" << endl;
		cout << "请记住这个字符串:" << endl;
		cout << gameAdmin->getContent() << endl;
		cout << "倒计时：";
		countdown(2);
		system("cls");
		cout << "------记忆小游戏------" << endl;
		cout << "请输入您刚刚看到的内容：" << endl;
		cin >> userAnswer;
		if (gameAdmin->checkAnswer(userAnswer)) {
			cout << "答案正确" << endl;
		}
		else
		{
			cout << "答案错误" << endl;
		}
		Sleep(800);
		system("cls");
	}
	viewGameEnd(degress);
}

void App::viewGameEnd(string degress)
{
	// 储存得分
	int score = gameAdmin->getTotalPoints();
	bool res = userAdmin->checkNewRecorder(atoi(degress.c_str()), score);
	cout << "------记忆小游戏------\n游戏结束," << endl;
	if (res)
	{
		cout << "恭喜你，获得了新纪录！" << endl;
	}
	cout << "你最后得分为：" << score << "分" << endl;
	cout << "\n1.再试一次\n2.返回主菜单\n请选择：";
	gameAdmin->reset();
	char i = '0';
	cin >> i;
	if (i == '1') viewGamePlay(degress);
	else if (i == '2') viewUserMenu();
	else viewUserMenu();
}

