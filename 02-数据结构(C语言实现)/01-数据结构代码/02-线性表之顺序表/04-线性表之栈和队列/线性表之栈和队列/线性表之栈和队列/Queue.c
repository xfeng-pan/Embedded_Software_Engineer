#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

//销毁
void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* follow = cur->next;
		free(cur);
		cur = follow;
	}
	pq->head = pq->tail = NULL;

}


QNode* BuyNode(QDataType x)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc failed!!!\r\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;

}

//入队
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = BuyNode(x);

	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	
}

//出队
void QueuePop(Queue* pq)
{
	assert(pq);//判断队列是否存在
	assert(pq->head);//判断存在的队列是否为空


	QNode* follow = pq->head->next;
	free(pq->head);
	pq->head = follow;

	if (pq->head == NULL) pq->tail = NULL;
}

//取数据：队头
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}

//取数据：队尾
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);

	return pq->tail->data;
}

//判断队内数据个数
int QueueSize(Queue* pq)
{
	int size = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

//判断队列是否为空，空为1， 非空为0
bool IsQueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
