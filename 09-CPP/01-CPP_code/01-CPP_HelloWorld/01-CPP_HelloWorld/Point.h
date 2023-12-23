#pragma once
#include <iostream>
using namespace std;

class Point
{
public:
	//设置X坐标
	void setX(int x);

	//获取X坐标
	int getX();

	//设置Y坐标
	void setY(int y);

	//获取Y坐标
	int getY();


private:
	int m_X;
	int m_Y;
};