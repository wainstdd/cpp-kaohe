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
/*#### 基类 Spaceship：
成员变量：model（型号），speed（速度），energy（能量）。 <br/>
虚成员函数：<br/>
showStats()：展示飞船的基本信息。<br/>
action()：执行飞船的特定功能（纯虚函数）。<br/>
*/
class cargoship :public spaceship
{
public:
	int cargocapacity;
	void loadcargo(int cargo)
	{
		Sleep(300);
		cout << "装载完成" << endl;
		cargocapacity -= cargo;
		Sleep(300);
		cout << "剩余容量：" << cargocapacity << endl;
		Sleep(300);
	}
	void action() override
	{
		Sleep(300);
		cout << "请输入运输量:" << endl;
		int cargo;
		cin >> cargo;
		Sleep(300);
		if (cargo > cargocapacity)
		{
			cout << "容量不足" << endl;
			return;
		}
		cout << "运输飞船正在装载货物" << endl;
		loadcargo(cargo);
	}
	
/*
#### 派生类 CargoShip（运输飞船）：
新增成员变量：cargoCapacity（货物容量）。<br/>
重写函数 action()：显示运输飞船正在装载货物。<br/>
新增函数 loadCargo(int cargo)：根据给定的货物数量进行装载，显示剩余货物容量。<br/>*/
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
			cout << "能量不足" << endl;
			return;
		}
		Sleep(300);
		cout << "激光已发射" << endl;
		Sleep(300);
		cout << "消耗能量：10" << endl;
		energe -= 10;
		Sleep(300);
		cout << "剩余能量：" << energe << endl;
	}
	void action() override
	{
		Sleep(300);
		cout << "战斗飞船即将发射激光" << endl;
		firelaser();
	}
};
/*
#### 派生类 BattleShip（战斗飞船）：
新增成员变量：weaponPower（武器威力）。<br/>
重写函数 action()：显示战斗飞船即将发射激光。<br/>
新增函数 fireLaser()：发射一次激光，减少一定能量。 <br/>
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
				cout << "能量不足" << endl;
				return;
			}
			Sleep(200);
			cout << "扫描中" << i * 10 << '%' << endl;
			Sleep(200);
			cout << "消耗能量：" << 1 * scanrange << endl;
			Sleep(200);
			energe -= 1 * scanrange;
			Sleep(200);
			cout << "剩余能量：" << energe << endl;
		}
	}
	void action() override
	{
		cout << "探索飞船正在扫描星球" << endl;
		scanplanet();
	}
};
/*
#### 派生类 ExplorerShip（探索飞船）：
新增成员变量：scanRange（扫描范围）。<br / >
重写函数 action()：显示探索飞船正在扫描星球。<br / >
新增函数 scanPlanet()：每隔一段时间消耗一定扫描星球消耗的能量, 显示剩余能量。<br / >
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
		cout << "----------------------------------菜单----------------------------------" << endl;
		cout << endl;
		cout << "1.租赁飞船                     2.增加飞船                 3.查看所有飞船" << endl;
		cout << endl;
		cout << "------------------------------------------------------------------------" << endl;
		int choose;
		cin >> choose;
		Sleep(300);
		if (choose == 1)
		{
			cout << "请选择要租赁的飞船：" << endl;
			Sleep(300);
			cout << "1.CargoShip（运输飞船）2.BattleShip（战斗飞船）3.ExplorerShip（探索飞船）" << endl;
			cin >> choose;
			if (choose == 1)
			{
				if (y == 0)
				{
					Sleep(200);
					cout << "飞船库里还没有这种飞船!" << endl;
					return;
				}
				cout << "选择要使用的飞船：" << endl;
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
				cout << "使用结束"<<endl;
				cout << endl;
			}
			if (choose == 2)
			{
				if (z == 0)
				{
					Sleep(200);
					cout << "飞船库里还没有这种飞船!" << endl;
					return;
				}
				cout << "选择要使用的飞船：" << endl;
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
				cout << "使用结束" << endl;
				cout << endl;
			}
			if (choose == 3)
			{
				if (t == 0)
				{
					Sleep(200);
					cout << "飞船库里还没有这种飞船!" << endl;
					return;
				}
				cout << "选择要使用的飞船：" << endl;
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
				cout << "使用结束" << endl;
				cout << endl;
			}
		}
		else if (choose == 2)
		{
			cout << "请选择要增加的飞船" << endl;
			Sleep(300);
			cout << "1.CargoShip（运输飞船）2.BattleShip（战斗飞船）3.ExplorerShip（探索飞船）" << endl;
			cin >> choose;
			if (choose == 1)
			{
				y++;
				Sleep(300);
				cout << "请设置运输飞船的参数：" << endl;
				Sleep(300);
				cout << "货物容量：" << endl;
				cin >> ys[y].cargocapacity;
				Sleep(300);
				cout << "速度：" << endl;
				cin >> ys[y].speed;
				Sleep(300);
				cout << "能量：" << endl;
				cin >> ys[y].energe;
				Sleep(500);
				cout << "增加成功" << endl;
			}
			else if (choose == 2)
			{
				z++;
				Sleep(300);
				cout << "请设置战斗飞船的参数：" << endl;
				Sleep(300);
				cout << "武器威力：" << endl;
				cin >> zd[z].weaponpower;
				Sleep(300);
				cout << "速度：" << endl;
				cin >> zd[z].speed;
				Sleep(300);
				cout << "能量：" << endl;
				cin >> zd[z].energe;
				Sleep(500);
				cout << "增加成功" << endl;
			}
			else if (choose == 3)
			{
				t++;
				Sleep(300);
				cout << "请设置探索飞船的参数：" << endl;
				Sleep(300);
				cout << "扫描范围：" << endl;
				cin >> ts[t].scanrange;
				Sleep(300);
				cout << "速度：" << endl;
				cin >> ts[t].speed;
				Sleep(300);
				cout << "能量：" << endl;
				cin >> ts[t].energe;
				Sleep(500);
				cout << "增加成功" << endl;
			}
		}
		else if (choose == 3)
		{
			cout << "CargoShip（运输飞船）：" << y << endl;
			cout << "BattleShip（战斗飞船）：" << z << endl;
			cout << "ExplorerShip（探索飞船）：" << t << endl;
		}
	}
};
int main()
{
	spaceshipfleet a;
	int n;
	cout << "要玩几轮？" << endl;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cout << "欢迎来到飞船库" << endl;
		Sleep(300);
		a.menu();
		Sleep(300);
		cout << "要继续吗" << endl;
		Sleep(300);
		cout << "1.继续  2.离开" << endl;
		int choose;
		cin >> choose;
		if (choose == 2)
			return 0;
	}	
	return 0;
}
/*#### 普通的类SpaceshipFleet（飞船库）：
自由发挥部分 :D
你需要：<br/>
1.写一个菜单，在菜单内能够选择租赁飞船，增加飞船与查看所有飞船。<br/>
2.在租赁飞船后调用对应飞船的 action() 函数和对应的特色函数（请注意运输飞船的特色函数需要输入货物数量），展示每种飞船的特定功能。<br/>
3.增加飞船时可以设定飞船的成员变量们的数值。<br/>
4.查看所有飞船时列出各种飞船的数量即可。<br/>
5.消耗能量消耗多少大家自由设计<br/>
*/
