////������Բ�͵�Ĺ�ϵ
//#include <iostream>
//using namespace std;
//
//#include "Point.h"
//#include "Circle.h"

//class Point
//{
//public:
//	//����X����
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	//��ȡX����
//	int getX()
//	{
//		return m_X;
//	}
//	//����Y����
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//	//��ȡY����
//	int getY()
//	{
//		return m_Y;
//	}
//
//private:
//	int m_X;
//	int m_Y;
//};

//class Circle
//{
//public:
//	//���ð뾶
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	//��ȡ�뾶
//	int getR()
//	{
//		return m_R;
//	}
//	//����Բ��
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//	//��ȡԲ��
//	Point getCenter()
//	{
//		return m_Center;
//	}
//private:
//	int m_R;
//	Point m_Center;
//
//};

////ȫ�ֺ����жϵ��Բ�Ĺ�ϵ
//void isInCircle(Circle& c, Point& p)
//{
//	//��������֮��ľ����ƽ��
//	int distance =
//		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
//		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
//
//	//����뾶��ƽ��
//	int rDistance = c.getR() * c.getR();
//
//	//�жϹ�ϵ
//	if (distance == rDistance)
//	{
//		cout << "����Բ�ϣ�ȫ�ֺ�����" << endl;
//	}
//	else if (distance < rDistance)
//	{
//		cout << "����Բ�ڣ�ȫ�ֺ�����" << endl;
//	}
//	else
//	{
//		cout << "����Բ�⣨ȫ�ֺ�����" << endl;
//	}
//
//}
//
//
//int main()
//{
//	Point pc;
//	pc.setX(2);
//	pc.setY(2);
//
//	Point pp;
//	pp.setX(2);
//	pp.setY(0);
//
//	Circle c1;
//	c1.setCenter(pc);
//	c1.setR(3);
//
//	isInCircle(c1, pp);
//
//	system("pause");
//	return 0;
//}

//������������
//#include <iostream>
//using namespace std;
//
//class Cube
//{
//public:
//	//���ó�
//	void set_L(int l)
//	{
//		m_L = l;
//	}
//	//��ȡ��
//	int get_L()
//	{
//		return m_L;
//	}
//
//	//���ÿ�
//	void set_W(int w)
//	{
//		m_W = w;
//	}
//	//��ȡ��
//	int get_W()
//	{
//		return m_W;
//	}
//	//���ø�
//	void set_H(int h)
//	{
//		m_H = h;
//	}
//	//��ȡ��
//	int get_H()
//	{
//		return m_H;
//	}
//	
//	//��ȡ���
//	int squre()
//	{
//		return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
//	}
//	//��ȡ���
//	int volume()
//	{
//		return m_L * m_W * m_H;
//	}
//
//	//���ó�Ա�����ж������������Ƿ����
//	bool isSamebyClass(Cube &c)
//	{
//		if(m_L == c.get_L() && m_W == c.get_W() && m_H == c.get_H())
//		{
//			cout << "������������ȣ���Ա������" << endl;
//			return true;
//		}
//		else
//		{
//			cout << "���������岻��ȣ���Ա������" << endl;
//			return false;
//		}
//	}
//private:
//	int m_L;
//	int m_W;
//	int m_H;
//};
//
////����ȫ�ֺ����ж������������Ƿ����
//bool isSame(Cube& c1, Cube& c2)
//{
//	if (c1.get_L() == c2.get_L() && c1.get_W() == c2.get_W() && c1.get_H() == c2.get_H())
//	{
//		cout << "������������ȣ�ȫ�ֺ�����" << endl;
//		return true;
//	}
//	else
//	{
//		cout << "���������岻��ȣ�ȫ�ֺ�����" << endl;
//		return false;
//	}
//}
//
//int main()
//{
//	//ʵ����һ������
//	Cube c1;
//	c1.set_L(2);
//	c1.set_W(4);
//	c1.set_H(6);
//
//	cout << c1.squre() << endl;
//	cout << c1.volume() << endl;
//
//	//��ʵ����һ������
//	Cube c2;
//	c2.set_L(2);
//	c2.set_W(4);
//	c2.set_H(6);
//
//	cout << c2.squre() << endl;
//	cout << c2.volume() << endl;
//
//	bool ret = isSame(c1, c2);
//	ret = c1.isSamebyClass(c2);
//
//
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <string>
//
//class Person
//{
//public:
//	string p_name;
//protected:
//	string p_car;
//private:
//	int p_password;
//
//public:
//	void func()
//	{
//		p_name = "pxf";
//		p_car = "bmw";
//		p_password = 123456;
//	}
//
//	void func2()
//	{
//		cout << p_password << endl;
//		p_password = 654321;
//		cout << p_password << endl;
//	}
//};
//
//
//int main()
//{
//	Person p1;
//	cout << p1.p_name << endl;
//
//	p1.func();
//
//	cout << p1.p_name << endl;
//
//	p1.func2();
//
//	system("pause");
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//const double PI = 3.14;
//
//class Circle
//{
//	//����Ȩ��
//	//����Ȩ��
//public:
//	//����
//	//�뾶
//	int m_r;
//
//	//��Ϊ
//	//��ȡԲ���ܳ�
//	double calculateZC()
//	{
//		return 2 * m_r * PI;
//	}
//};
//
//int main()
//{
//	//ͨ��Բ�� ������һ�������Բ��
//	Circle c1;
//	//��Բ��������Խ��и�ֵ
//	c1.m_r = 10;
//
//	//ͨ����Ϊ�����Բ���ܳ�
//	cout << "Բ���ܳ�Ϊ��" << c1.calculateZC() << endl;
//
//	system("pause");
//	return 0;
//}


