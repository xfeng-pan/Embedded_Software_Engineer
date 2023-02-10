#pragma once

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#include <string.h>
#include <stdio.h>


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
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_NAME];
	char tele[MAX_TELE];
	char addres[MAX_ADDR];
};

//ͨѶ¼����
struct Contact
{
	struct PeoInfo data[MAX];//���嵱ǰͨѶ¼����ܴ�����˵���Ϣ
	int size;//��¼��ǰ�Ѿ��ж����˵���Ϣ
};



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

