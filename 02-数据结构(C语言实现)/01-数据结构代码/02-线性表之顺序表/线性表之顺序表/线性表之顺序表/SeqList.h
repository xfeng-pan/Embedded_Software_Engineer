#pragma once
//#ifndef __SEQLIST__H__
//#defien __SEQLIST__H__
//...
//#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


//��ǿ����Ŀ�ά����
#define MAX_SIZE 100

typedef int SQDataType;

//��̬˳���
//typedef struct SeqList
//{
//	SQDataType a[MAX_SIZE];
//	int size;
//}SL;

//��̬˳���
typedef struct SeqList
{
	SQDataType* a;
	int size;
	int capacity;
}SL;



//��ɾ��ĵȽӿں���
void SeqListInit(SL* ps);//��ʼ��
void SeqListPrint(SL* ps);//��ӡ
void SeqListPushBack(SL* ps, SQDataType x);//β������
void SeqListPushFront(SL* ps, SQDataType x);//ͷ������
void SeqListPopBack(SL* ps);//β��ɾ��
void seqListPopFront(SL* ps);//ͷ��ɾ��






