#include<iostream>
#include <windows.h>
using namespace std;
class spaceship
{
public:
	int model;
	int speed;
	int energe;
	virtual void showstates()
	{
		cout << model << endl;
		cout << speed << endl;
		cout << energe << endl;
	}
	virtual void action() = 0;
};
/*#### ���� Spaceship��
��Ա������model���ͺţ���speed���ٶȣ���energy���������� <br/>
���Ա������<br/>
showStats()��չʾ�ɴ��Ļ�����Ϣ��<br/>
action()��ִ�зɴ����ض����ܣ����麯������<br/>
*/
class cargoship :public spaceship
{
public:
	int cargocapacity;
	void loadcargo(int cargo)
	{
		Sleep(300);
		cout << "װ�����" << endl;
		cargocapacity -= cargo;
		Sleep(300);
		cout << "ʣ��������" << cargocapacity << endl;
		Sleep(300);
	}
	void action() override
	{
		Sleep(300);
		cout << "������������:" << endl;
		int cargo;
		cin >> cargo;
		Sleep(300);
		if (cargo > cargocapacity)
		{
			cout << "��������" << endl;
			return;
		}
		cout << "����ɴ�����װ�ػ���" << endl;
		loadcargo(cargo);
	}
	
/*
#### ������ CargoShip������ɴ�����
������Ա������cargoCapacity��������������<br/>
��д���� action()����ʾ����ɴ�����װ�ػ��<br/>
�������� loadCargo(int cargo)�����ݸ����Ļ�����������װ�أ���ʾʣ�����������<br/>*/
};
class battleship :public spaceship
{
public:
	int weaponpower;
	void firelaser()
	{
		Sleep(300);
		if (energe < 10)
		{
			cout << "��������" << endl;
			return;
		}
		Sleep(300);
		cout << "�����ѷ���" << endl;
		Sleep(300);
		cout << "����������10" << endl;
		energe -= 10;
		Sleep(300);
		cout << "ʣ��������" << energe << endl;
	}
	void action() override
	{
		Sleep(300);
		cout << "ս���ɴ��������伤��" << endl;
		firelaser();
	}
};
/*
#### ������ BattleShip��ս���ɴ�����
������Ա������weaponPower��������������<br/>
��д���� action()����ʾս���ɴ��������伤�⡣<br/>
�������� fireLaser()������һ�μ��⣬����һ�������� <br/>
*/
class explorership :public spaceship
{
public:
	int scanrange;
	void scanplanet()
	{
		for (int i = 1;i <= 10;i++)
		{
			if (energe < 1 * scanrange)
			{
				cout << "��������" << endl;
				return;
			}
			Sleep(200);
			cout << "ɨ����" << i * 10 << '%' << endl;
			Sleep(200);
			cout << "����������" << 1 * scanrange << endl;
			Sleep(200);
			energe -= 1 * scanrange;
			Sleep(200);
			cout << "ʣ��������" << energe << endl;
		}
	}
	void action() override
	{
		cout << "̽���ɴ�����ɨ������" << endl;
		scanplanet();
	}
};
/*
#### ������ ExplorerShip��̽���ɴ�����
������Ա������scanRange��ɨ�跶Χ����<br / >
��д���� action()����ʾ̽���ɴ�����ɨ������<br / >
�������� scanPlanet()��ÿ��һ��ʱ������һ��ɨ���������ĵ�����, ��ʾʣ��������<br / >
*/
int y = 0, z = 0, t = 0;
cargoship ys[10];
battleship zd[10];
explorership ts[10];
class spaceshipfleet
{
public:
	void menu()
	{
		cout << "----------------------------------�˵�----------------------------------" << endl;
		cout << endl;
		cout << "1.���޷ɴ�                     2.���ӷɴ�                 3.�鿴���зɴ�" << endl;
		cout << endl;
		cout << "------------------------------------------------------------------------" << endl;
		int choose;
		cin >> choose;
		Sleep(300);
		if (choose == 1)
		{
			cout << "��ѡ��Ҫ���޵ķɴ���" << endl;
			Sleep(300);
			cout << "1.CargoShip������ɴ���2.BattleShip��ս���ɴ���3.ExplorerShip��̽���ɴ���" << endl;
			cin >> choose;
			if (choose == 1)
			{
				if (y == 0)
				{
					Sleep(200);
					cout << "�ɴ����ﻹû�����ַɴ�!" << endl;
					return;
				}
				cout << "ѡ��Ҫʹ�õķɴ���" << endl;
				Sleep(300);
				for (int i = 1;i <= y;i++)
				{
					cout << i << ' ';
					Sleep(100);
				}
				cout << endl;
				cin >> choose;
				ys[choose].action();
				ys[choose].energe += 50;
				cout << "ʹ�ý���"<<endl;
				cout << endl;
			}
			if (choose == 2)
			{
				if (z == 0)
				{
					Sleep(200);
					cout << "�ɴ����ﻹû�����ַɴ�!" << endl;
					return;
				}
				cout << "ѡ��Ҫʹ�õķɴ���" << endl;
				Sleep(300);
				for (int i = 1;i <= z;i++)
				{
					cout << i << ' ';
					Sleep(100);
				}
				cout << endl;
				cin >> choose;
				zd[choose].action();
				zd[choose].energe += 50;
				cout << "ʹ�ý���" << endl;
				cout << endl;
			}
			if (choose == 3)
			{
				if (t == 0)
				{
					Sleep(200);
					cout << "�ɴ����ﻹû�����ַɴ�!" << endl;
					return;
				}
				cout << "ѡ��Ҫʹ�õķɴ���" << endl;
				Sleep(300);
				for (int i = 1;i <= t;i++)
				{
					cout << i << ' ';
					Sleep(100);
				}
				cout << endl;
				cin >> choose;
				ts[choose].action();
				ts[choose].energe += 50;
				cout << "ʹ�ý���" << endl;
				cout << endl;
			}
		}
		else if (choose == 2)
		{
			cout << "��ѡ��Ҫ���ӵķɴ�" << endl;
			Sleep(300);
			cout << "1.CargoShip������ɴ���2.BattleShip��ս���ɴ���3.ExplorerShip��̽���ɴ���" << endl;
			cin >> choose;
			if (choose == 1)
			{
				y++;
				Sleep(300);
				cout << "����������ɴ��Ĳ�����" << endl;
				Sleep(300);
				cout << "����������" << endl;
				cin >> ys[y].cargocapacity;
				Sleep(300);
				cout << "�ٶȣ�" << endl;
				cin >> ys[y].speed;
				Sleep(300);
				cout << "������" << endl;
				cin >> ys[y].energe;
				Sleep(500);
				cout << "���ӳɹ�" << endl;
			}
			else if (choose == 2)
			{
				z++;
				Sleep(300);
				cout << "������ս���ɴ��Ĳ�����" << endl;
				Sleep(300);
				cout << "����������" << endl;
				cin >> zd[z].weaponpower;
				Sleep(300);
				cout << "�ٶȣ�" << endl;
				cin >> zd[z].speed;
				Sleep(300);
				cout << "������" << endl;
				cin >> zd[z].energe;
				Sleep(500);
				cout << "���ӳɹ�" << endl;
			}
			else if (choose == 3)
			{
				t++;
				Sleep(300);
				cout << "������̽���ɴ��Ĳ�����" << endl;
				Sleep(300);
				cout << "ɨ�跶Χ��" << endl;
				cin >> ts[t].scanrange;
				Sleep(300);
				cout << "�ٶȣ�" << endl;
				cin >> ts[t].speed;
				Sleep(300);
				cout << "������" << endl;
				cin >> ts[t].energe;
				Sleep(500);
				cout << "���ӳɹ�" << endl;
			}
		}
		else if (choose == 3)
		{
			cout << "CargoShip������ɴ�����" << y << endl;
			cout << "BattleShip��ս���ɴ�����" << z << endl;
			cout << "ExplorerShip��̽���ɴ�����" << t << endl;
		}
	}
};
int main()
{
	spaceshipfleet a;
	int n;
	cout << "Ҫ�漸�֣�" << endl;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cout << "��ӭ�����ɴ���" << endl;
		Sleep(300);
		a.menu();
		Sleep(300);
		cout << "Ҫ������" << endl;
		Sleep(300);
		cout << "1.����  2.�뿪" << endl;
		int choose;
		cin >> choose;
		if (choose == 2)
			return 0;
	}	
	return 0;
}
/*#### ��ͨ����SpaceshipFleet���ɴ��⣩��
���ɷ��Ӳ��� :D
����Ҫ��<br/>
1.дһ���˵����ڲ˵����ܹ�ѡ�����޷ɴ������ӷɴ���鿴���зɴ���<br/>
2.�����޷ɴ�����ö�Ӧ�ɴ��� action() �����Ͷ�Ӧ����ɫ��������ע������ɴ�����ɫ������Ҫ���������������չʾÿ�ַɴ����ض����ܡ�<br/>
3.���ӷɴ�ʱ�����趨�ɴ��ĳ�Ա�����ǵ���ֵ��<br/>
4.�鿴���зɴ�ʱ�г����ַɴ����������ɡ�<br/>
5.�����������Ķ��ٴ���������<br/>
*/