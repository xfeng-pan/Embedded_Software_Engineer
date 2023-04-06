#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int SLTDataType;//�������������

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;//����һ��ָ�룬ָ�����һ���ṹ��
}SLTNode;

//����ı������ͷָ�룬��һ��ָ��
void SListPrint(SLTNode* phead);
//��ı������ͷָ�룬������ָ��
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPushFront(SLTNode** pphead, SLTDataType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);

SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//��pos��ǰ�����x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//ɾ��posλ�õ�ֵ
void SListErase(SLTNode** pphead, SLTNode* pos);












