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
	string username, password;
	cout << "�������û�����";
	cin >> username;
	cout << "���������룺";
	cin >> password;
	userAdmin->reg(username, password);
	viewStartMenu();
}

void App::viewLogin()
{
	string username, password;
	cout << "�������û�����";
	cin >> username;
	cout << "���������룺";
	cin >> password;
	bool res;
	res = userAdmin->login(username, password);
	if (res)
	{
		viewUserMenu();
	}
	else
	{
		cout << "��¼ʧ�ܣ�����������!" << endl;
		viewLogin();
	}
}

void App::viewUserMenu()
{
	char choose;
	cout << "-----��ӭ����������Ϸ-----" << endl;
	cout << "1.��ʼ��Ϸ" << endl;
	cout << "2.��������" << endl;
	cout << "��ѡ��:";
	cin >> choose;
	if (choose == '1') viewLogin();
	else if (choose == '2') viewRegister();
	else exit(0);
}

void App::viewRankAdmin()
{
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
}

void App::viewGameAdmin()
{
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
		viewRankAdmin();
	}
}

void App::viewGamePlay(string degree)
{
}
