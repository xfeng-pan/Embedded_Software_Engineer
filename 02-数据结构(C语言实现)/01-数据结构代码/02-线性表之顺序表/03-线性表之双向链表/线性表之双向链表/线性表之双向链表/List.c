#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//�����½ڵ�
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

//��ʼ��
ListNode* ListInit(void)
{
	ListNode* newnode = BuyListNode(0);
	newnode->next = newnode;
	newnode->prev = newnode;

	return newnode;
}


//��ӡ
void ListPrint(ListNode* phead)
{
	ListNode* tail = phead->next;
	printf("phead -> ");

	while (tail != phead)
	{
		printf("%d -> ", tail->data);
		tail = tail->next;
	}
	printf("phead\r\n");
}


//����
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* follow = cur->next;
		printf("Destory: %p -> %d \r\n", cur, cur->data);
		free(cur);
		cur = follow;
	}
	free(phead);
	phead = NULL;

}

//β�壬���Ը���ListInsert: ListInsert(phead, x);
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);
	phead->prev = newnode;
	newnode->next = phead;
	newnode->prev = tail;
	tail->next = newnode;

}

void ListPushBack2(ListNode** pphead, LTDataType x)
{
	assert(pphead);
	ListNode* tail = (*pphead)->prev;
	ListNode* newnode = BuyListNode(x);
	tail->next = newnode;
	newnode->next = *pphead;
	newnode->prev = tail;
	(*pphead)->prev = newnode;
}

//ͷ�壬ͬ�����Ը���ListInsert��ListInsert(phead->next, x);
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);

	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;

}

//ͷɾ�����Ը���LisrErase��ListErase(phead->next);
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = second;
	second->prev = phead;

	free(first);
	first = NULL;
}
//βɾ�����Ը���LisrErase��ListErase(phead->prev);
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->prev;
	ListNode* penultimate = tail->prev;

	penultimate->next = phead;
	phead->prev = penultimate;

	free(tail);
	tail = NULL;
}

//����
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
	
}

// ��posǰ����x
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* Pre = pos->prev;
	assert(newnode);
	Pre->next = newnode;
	newnode->next = pos;
	pos->prev = newnode;
	newnode->prev = Pre;
}


// ɾ��posλ�õ�ֵ
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* last = pos->prev;
	ListNode* follow = pos->next;

	last->next = follow;
	follow->prev = last;

	free(pos);
	pos = NULL;
}







