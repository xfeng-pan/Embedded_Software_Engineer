#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

//����
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

//���
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

//����
void QueuePop(Queue* pq)
{
	assert(pq);//�ж϶����Ƿ����
	assert(pq->head);//�жϴ��ڵĶ����Ƿ�Ϊ��


	QNode* follow = pq->head->next;
	free(pq->head);
	pq->head = follow;

	if (pq->head == NULL) pq->tail = NULL;
}

//ȡ���ݣ���ͷ
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}

//ȡ���ݣ���β
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);

	return pq->tail->data;
}

//�ж϶������ݸ���
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

//�ж϶����Ƿ�Ϊ�գ���Ϊ1�� �ǿ�Ϊ0
bool IsQueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
