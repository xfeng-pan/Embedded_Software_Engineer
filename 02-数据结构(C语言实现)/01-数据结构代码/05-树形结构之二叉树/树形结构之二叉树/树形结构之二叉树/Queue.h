#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//前置声明
struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDataType;


//用链表来实现队列，这是链表中的每个节点
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

//队列的结构体：只需要存储队头和队尾的指针
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

//相关函数

//初始化
void QueueInit(Queue* pq);

//销毁
void QueueDestory(Queue* pq);


//入队
void QueuePush(Queue* pq, QDataType x);

//出队
void QueuePop(Queue* pq);

//取数据：队头
QDataType QueueFront(Queue* pq);

//取数据：队尾
QDataType QueueBack(Queue* pq);

//判断队内数据个数
int QueueSize(Queue* pq);

//判断队列是否为空，空为1， 非空为0
bool IsQueueEmpty(Queue* pq);


