#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

struct Book
{
	char name[40];
	float price;
};

int main()
{
	struct Book b1 = { "C语言程序设计",12.99 };
	struct Book* pb = &b1;//结构体指针

	strcpy(pb->name, "C++程序设计");
	printf("新书名：%s\n", (*pb).name);
	return 0;
}
	//printf("-------------------------\n");
	//printf("利用结构体打印和修改信息\n");
	//printf("书名：%s\n", b1.name);
	//printf("价格：%.2f\n", b1.price);
	//printf("八五折后的价格为：%.2f\n", b1.price * 0.85);
	//printf("-------------------------\n");
	//printf("利用指针打印和修改信息\n");
	//printf("书名：%s\n", (*pb).name);
	//printf("价格：%.2f\n", (*pb).price);
	//printf("八五折后的价格为：%.2f\n", (*pb).price * 0.85);
	//printf("-------------------------\n");
	//printf("利用指针->打印和修改信息\n");
	//printf("书名：%s\n", pb->name);
	//printf("价格：%.2f\n", pb->price);
	//printf("八五折后的价格为：%.2f\n", pb->price * 0.85);
//	return 0;
//}