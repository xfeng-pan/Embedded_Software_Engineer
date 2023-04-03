#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"


void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\r\n");
}

SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	//�����µĿռ�
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//Ѱ��β�ڵ�
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		//�����µ�β�ڵ�
		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;

}

void SListPopBack(SLTNode** pphead)
{
	//assert(*pphead);
	SLTNode* prev = NULL;
	SLTNode* tail = *pphead;

	//1. ������
	if (*pphead == NULL)
	{
		return;
	}
	//2. ֻ��һ���ڵ�
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//3. �ж������ڵ�
	else
	{
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}

		prev->next = NULL;
		free(tail);
	}

}

void SListPopFront(SLTNode** pphead)
{
	assert(*pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
	

}

SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);

	SLTNode* prev = *pphead;

	if (pos == *pphead)
	{
		SListPushFront(pphead,x);
		return;
	}

	while (prev->next != pos)
	{
		prev = prev->next;
	}

	prev->next = newnode;
	newnode->next = pos;
}


void SListErase(SLTNode** pphead, SLTNode* pos)
{
	SLTNode* prev = *pphead;

	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
	
}




















