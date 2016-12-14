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
	cout << "-----��ӭ����������Ϸ-----" << endl;
	cout << "1.��¼�˺Ž�����Ϸ" << endl;
	cout << "2.ע���˺�" << endl;
	cout << "��ѡ��:";
	cin >> choose;
	if (choose == '1') viewLogin();
	else if (choose == '2') viewRegister();
	else exit(0);
}

void App::viewRegister()
{
	system("cls");
	string username, password;
	cout << "-----�û�ע��-----" << endl;
	cout << "�������û�����";
	cin >> username;
	cout << "���������룺";
	cin >> password;
	userAdmin->reg(username, password);
	viewStartMenu();
}

void App::viewLogin()
{
	system("cls");
	cout << "-----�û���¼-----" << endl;
	string username, password;
	cout << "�������û�����";
	cin >> username;
	cout << "���������룺";
	cin >> password;
	bool res;
	res = userAdmin->login(username, password);
	if (res)
	{
		cout << "��¼�ɹ���" << endl;
		Sleep(1000);
		viewUserMenu();
	}
	else
	{
		cout << "��¼ʧ�ܣ������µ�¼!" << endl;
		Sleep(1500);
		viewLogin();
	}
}

void App::viewUserMenu()
{
	system("cls");
	char choose;
	cout << "-----��ӭ����������Ϸ-----" << endl;
	cout << "1.��ʼ��Ϸ" << endl;
	cout << "2.��������" << endl;
	cout << "3.�˳���Ϸ" << endl;
	cout << "��ѡ��:";
	cin >> choose;
	if (choose == '1') viewGameAdmin();
	else if (choose == '2') viewRankAdmin();
	else exit(0);
}

void App::viewRankAdmin()
{
	system("cls");
	string choose;
	cout << "-----��������-----" << endl;
	cout << "1.��" << endl;
	cout << "2.һ��" << endl;
	cout << "3.����" << endl;
	cout << "��ѡ��鿴�������Ѷ�:";
	cin >> choose;
	if (choose == "1") viewRankList(choose);
	else if (choose == "2") viewRankList(choose);
	else if (choose == "3") viewRankList(choose);
	else if (choose == "0") viewUserMenu();
	else {
		cout << "�ѶȲ����ڣ�������ѡ��!";
		viewRankAdmin();
	}
}

void App::viewRankList(string type)
{
	system("cls");
	vector<int> scoreList;
	scoreList = userAdmin->getScoreList(atoi(type.c_str()));
	cout << "���������գ�" << endl;
	for (int i = 0; i < scoreList.size(); i++)
	{
		cout << "��" << i + 1 << "����" << scoreList[i] << endl;
	}
	cout << "\n1.�鿴��������\n2.�������˵�\n��ѡ��";
	char i = '0';
	cin >> i;
	if (i == '1') viewRankAdmin();
	else if (i == '2') viewUserMenu();
}

void App::viewGameAdmin()
{
	system("cls");
	string choose;
	cout << "-----��Ϸ�Ѷ�ѡ��-----" << endl;
	cout << "1.��" << endl;
	cout << "2.һ��" << endl;
	cout << "3.����" << endl;
	cout << "��ѡ����Ϸ���Ѷ�:";
	cin >> choose;
	if (choose == "1") viewGamePlay(choose);
	else if (choose == "2") viewGamePlay(choose);
	else if (choose == "3") viewGamePlay(choose);
	else if (choose == "0") viewUserMenu();
	else {
		cout << "�ѶȲ����ڣ�������ѡ��!";
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
	cout << "��Ϸ���Ͽ�ʼ������5���ӵ�ʱ��ȥ������Ļ�ϳ��ֵ��ַ�����Ȼ��д����" << endl;
	cout << "------���������ַ���ʼ��Ϸ------" << endl;
	cin >> tmp;
	system("cls");
	string userAnswer;
	gameAdmin->setGameDegress(degress);
	for (int i = 0; i < 1; i++)
	{
		cout << "------����С��Ϸ------(������" << gameAdmin->getTotalPoints() << "��)" << endl;
		cout << "���ס����ַ���:" << endl;
		cout << gameAdmin->getContent() << endl;
		cout << "����ʱ��";
		countdown(2);
		system("cls");
		cout << "------����С��Ϸ------" << endl;
		cout << "���������ոտ��������ݣ�" << endl;
		cin >> userAnswer;
		if (gameAdmin->checkAnswer(userAnswer)) {
			cout << "����ȷ" << endl;
		}
		else
		{
			cout << "�𰸴���" << endl;
		}
		Sleep(800);
		system("cls");
	}
	viewGameEnd(degress);
}

void App::viewGameEnd(string degress)
{
	// ����÷�
	int score = gameAdmin->getTotalPoints();
	bool res = userAdmin->checkNewRecorder(atoi(degress.c_str()), score);
	cout << "------����С��Ϸ------\n��Ϸ����," << endl;
	if (res)
	{
		cout << "��ϲ�㣬������¼�¼��" << endl;
	}
	cout << "�����÷�Ϊ��" << score << "��" << endl;
	cout << "\n1.����һ��\n2.�������˵�\n��ѡ��";
	gameAdmin->reset();
	char i = '0';
	cin >> i;
	if (i == '1') viewGamePlay(degress);
	else if (i == '2') viewUserMenu();
	else viewUserMenu();
}

