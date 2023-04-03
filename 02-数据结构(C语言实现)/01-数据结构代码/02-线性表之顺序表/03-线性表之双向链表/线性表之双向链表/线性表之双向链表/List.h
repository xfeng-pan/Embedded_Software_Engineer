#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

// 初始化，打印，销毁
// 头插，尾插
// 头删，尾删
ListNode* ListInit(void);
void ListPrint(ListNode* phead);
void ListDestory(ListNode** phead);
void ListPushBack(ListNode* phead, LTDataType x);
void ListPushBack2(ListNode** pphead, LTDataType x);
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);
void ListPopBack(ListNode* phead);

// 查找

ListNode* ListFind(ListNode* phead, LTDataType x);

// 在pos前插入x
void ListInsert(ListNode* pos, LTDataType x);


// 删除pos位置的值
void ListErase(ListNode* pos);
