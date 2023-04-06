#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int SLTDataType;//链表的数据类型

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;//这是一个指针，指向的是一个结构体
}SLTNode;

//不会改变链表的头指针，传一级指针
void SListPrint(SLTNode* phead);
//会改变链表的头指针，传二级指针
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPushFront(SLTNode** pphead, SLTDataType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);

SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//在pos的前面插入x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//删除pos位置的值
void SListErase(SLTNode** pphead, SLTNode* pos);












