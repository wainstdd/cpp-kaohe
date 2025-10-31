#include<iostream>
using namespace std;
class rectangle
{
public:
	int m_l, m_w;
	int area()
	{
		return m_l * m_w;
	}
	void display()
	{
		cout << m_l << ' ' << m_w << ' ' << area();
	}
	bool operator>(rectangle &b)
	{
		return this->area() > b.area();
	}
};
int main()
{
	rectangle a, b;
	cin >> a.m_l >> a.m_w >> b.m_l >> b.m_w;
	if (a > b)
		a.display();
	else
		b.display();
	return 0;
}
