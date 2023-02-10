#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct Point
{
	int x;
	int y;
}p1;//声明类型的同时定义变量p1

struct Point p2;//定义结构体变量p2

struct Point p3 = { 1,2 };//定义变量的同时进行初始化赋值



//typedef struct Stu
//{
//	//成员变量
//	char name[20];
//	int age;
//	char tele[12];
//	char sex[5];
//}STU;
//
//int main()
//{
//	STU s1 = {"panxfeng",12,"111111","male"};
//	s1.age = 12 ;
//	printf("%s\n", s1.name);
//	return 0;
//}




//#include <stdio.h>
//
////描述一个学生
////需要名字
////年龄
////电话
////性别
//
////sturct-结构体关键字
////Stu-结构体标签（自己随便取）
//struct Stu
//{
//	//成员变量
//	char name[20];
//	int age;
//	char tele[12];
//	char sex[5];
//}s1,s2,s3;//这三个是全局的结构体变量
//
//
//int main()
//{
//	struct Stu s;//结构体关键字 结构体标签 结构体变量名
//
//	return 0;
//		
//}













