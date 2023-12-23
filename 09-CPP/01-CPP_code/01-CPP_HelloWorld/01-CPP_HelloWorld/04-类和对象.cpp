////案例：圆和点的关系
//#include <iostream>
//using namespace std;
//
//#include "Point.h"
//#include "Circle.h"

//class Point
//{
//public:
//	//设置X坐标
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	//获取X坐标
//	int getX()
//	{
//		return m_X;
//	}
//	//设置Y坐标
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//	//获取Y坐标
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
//	//设置半径
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	//获取半径
//	int getR()
//	{
//		return m_R;
//	}
//	//设置圆心
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//	//获取圆心
//	Point getCenter()
//	{
//		return m_Center;
//	}
//private:
//	int m_R;
//	Point m_Center;
//
//};

////全局函数判断点和圆的关系
//void isInCircle(Circle& c, Point& p)
//{
//	//计算两点之间的距离的平方
//	int distance =
//		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
//		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
//
//	//计算半径的平方
//	int rDistance = c.getR() * c.getR();
//
//	//判断关系
//	if (distance == rDistance)
//	{
//		cout << "点在圆上（全局函数）" << endl;
//	}
//	else if (distance < rDistance)
//	{
//		cout << "点在圆内（全局函数）" << endl;
//	}
//	else
//	{
//		cout << "点在圆外（全局函数）" << endl;
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

//案例；立方体
//#include <iostream>
//using namespace std;
//
//class Cube
//{
//public:
//	//设置长
//	void set_L(int l)
//	{
//		m_L = l;
//	}
//	//获取长
//	int get_L()
//	{
//		return m_L;
//	}
//
//	//设置宽
//	void set_W(int w)
//	{
//		m_W = w;
//	}
//	//获取宽
//	int get_W()
//	{
//		return m_W;
//	}
//	//设置高
//	void set_H(int h)
//	{
//		m_H = h;
//	}
//	//获取高
//	int get_H()
//	{
//		return m_H;
//	}
//	
//	//获取面积
//	int squre()
//	{
//		return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
//	}
//	//获取体积
//	int volume()
//	{
//		return m_L * m_W * m_H;
//	}
//
//	//利用成员函数判断两个立方体是否相等
//	bool isSamebyClass(Cube &c)
//	{
//		if(m_L == c.get_L() && m_W == c.get_W() && m_H == c.get_H())
//		{
//			cout << "两个立方体相等（成员函数）" << endl;
//			return true;
//		}
//		else
//		{
//			cout << "两个立方体不相等（成员函数）" << endl;
//			return false;
//		}
//	}
//private:
//	int m_L;
//	int m_W;
//	int m_H;
//};
//
////利用全局函数判断两个立方体是否相等
//bool isSame(Cube& c1, Cube& c2)
//{
//	if (c1.get_L() == c2.get_L() && c1.get_W() == c2.get_W() && c1.get_H() == c2.get_H())
//	{
//		cout << "两个立方体相等（全局函数）" << endl;
//		return true;
//	}
//	else
//	{
//		cout << "两个立方体不相等（全局函数）" << endl;
//		return false;
//	}
//}
//
//int main()
//{
//	//实例化一个对象
//	Cube c1;
//	c1.set_L(2);
//	c1.set_W(4);
//	c1.set_H(6);
//
//	cout << c1.squre() << endl;
//	cout << c1.volume() << endl;
//
//	//再实例化一个对象
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
//	//访问权限
//	//公共权限
//public:
//	//属性
//	//半径
//	int m_r;
//
//	//行为
//	//获取圆的周长
//	double calculateZC()
//	{
//		return 2 * m_r * PI;
//	}
//};
//
//int main()
//{
//	//通过圆类 来创建一个具体的圆；
//	Circle c1;
//	//给圆对象的属性进行赋值
//	c1.m_r = 10;
//
//	//通过行为来输出圆的周长
//	cout << "圆的周长为：" << c1.calculateZC() << endl;
//
//	system("pause");
//	return 0;
//}


