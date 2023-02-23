#pragma once






//#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <malloc.h>


enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};


//联系人信息结构体
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_NAME];
	char tele[MAX_TELE];
	char addres[MAX_ADDR];
}PeoInfo;

//通讯录类型
typedef struct Contact
{
	struct PeoInfo *data;//定义一个指向PeopInfo类型结构体的指针
	int size;//记录当前已经有多少人的信息
	int capacity;//记录当前通讯录的容量
}Contact;



//声明函数
// 
//初始化通讯录
void InitContact(struct Contact* ps);

//增加一个元素到通讯录中
void AddContact(struct Contact* ps);

//显示通讯录
void ShowContact(const struct Contact* ps);

//删除通讯录中的指定联系人
void DelContact(struct Contact* ps);

//查找指定人的信息
void SearchContact(const struct Contact* ps);

//修改指定人的信息
void ModifyContact(struct Contact* ps);

//释放动态开辟的内存
void DestroyContact(struct Contact* ps);

