#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//ǰ������
struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDataType;


//��������ʵ�ֶ��У����������е�ÿ���ڵ�
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

//���еĽṹ�壺ֻ��Ҫ�洢��ͷ�Ͷ�β��ָ��
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

//��غ���

//��ʼ��
void QueueInit(Queue* pq);

//����
void QueueDestory(Queue* pq);


//���
void QueuePush(Queue* pq, QDataType x);

//����
void QueuePop(Queue* pq);

//ȡ���ݣ���ͷ
QDataType QueueFront(Queue* pq);

//ȡ���ݣ���β
QDataType QueueBack(Queue* pq);

//�ж϶������ݸ���
int QueueSize(Queue* pq);

//�ж϶����Ƿ�Ϊ�գ���Ϊ1�� �ǿ�Ϊ0
bool IsQueueEmpty(Queue* pq);


