#pragma once
//#ifndef __SEQLIST__H__
//#defien __SEQLIST__H__
//...
//#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


//增强程序的可维护性
#define MAX_SIZE 100

typedef int SQDataType;

//静态顺序表
//typedef struct SeqList
//{
//	SQDataType a[MAX_SIZE];
//	int size;
//}SL;

//动态顺序表
typedef struct SeqList
{
	SQDataType* a;
	int size;
	int capacity;
}SL;



//增删查改等接口函数
void SeqListInit(SL* ps);//初始化
void SeqListPrint(SL* ps);//打印
void SeqListPushBack(SL* ps, SQDataType x);//尾部插入
void SeqListPushFront(SL* ps, SQDataType x);//头部插入
void SeqListPopBack(SL* ps);//尾部删除
void seqListPopFront(SL* ps);//头部删除






