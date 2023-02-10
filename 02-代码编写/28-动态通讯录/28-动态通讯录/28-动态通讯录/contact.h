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


//��ϵ����Ϣ�ṹ��
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_NAME];
	char tele[MAX_TELE];
	char addres[MAX_ADDR];
}PeoInfo;

//ͨѶ¼����
typedef struct Contact
{
	struct PeoInfo *data;//����һ��ָ��PeopInfo���ͽṹ���ָ��
	int size;//��¼��ǰ�Ѿ��ж����˵���Ϣ
	int capacity;//��¼��ǰͨѶ¼������
}Contact;



//��������
// 
//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps);

//����һ��Ԫ�ص�ͨѶ¼��
void AddContact(struct Contact* ps);

//��ʾͨѶ¼
void ShowContact(const struct Contact* ps);

//ɾ��ͨѶ¼�е�ָ����ϵ��
void DelContact(struct Contact* ps);

//����ָ���˵���Ϣ
void SearchContact(const struct Contact* ps);

//�޸�ָ���˵���Ϣ
void ModifyContact(struct Contact* ps);

