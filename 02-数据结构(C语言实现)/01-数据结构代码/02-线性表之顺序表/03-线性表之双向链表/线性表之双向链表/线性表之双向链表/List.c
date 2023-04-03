#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//申请新节点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

//初始化
ListNode* ListInit(void)
{
	ListNode* newnode = BuyListNode(0);
	newnode->next = newnode;
	newnode->prev = newnode;

	return newnode;
}


//打印
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


//销毁
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

//尾插，可以复用ListInsert: ListInsert(phead, x);
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

//头插，同样可以复用ListInsert：ListInsert(phead->next, x);
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

//头删，可以复用LisrErase：ListErase(phead->next);
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
//尾删，可以复用LisrErase：ListErase(phead->prev);
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

//查找
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

// 在pos前插入x
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


// 删除pos位置的值
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







