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

// ��ʼ������ӡ������
// ͷ�壬β��
// ͷɾ��βɾ
ListNode* ListInit(void);
void ListPrint(ListNode* phead);
void ListDestory(ListNode** phead);
void ListPushBack(ListNode* phead, LTDataType x);
void ListPushBack2(ListNode** pphead, LTDataType x);
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);
void ListPopBack(ListNode* phead);

// ����

ListNode* ListFind(ListNode* phead, LTDataType x);

// ��posǰ����x
void ListInsert(ListNode* pos, LTDataType x);


// ɾ��posλ�õ�ֵ
void ListErase(ListNode* pos);
