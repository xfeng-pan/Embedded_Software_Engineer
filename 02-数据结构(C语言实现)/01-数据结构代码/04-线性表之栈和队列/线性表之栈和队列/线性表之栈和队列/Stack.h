#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

// ջ������ʵ�ַ�����
// 1. ����, 
// 2. ����

//#define MAX 100;

typedef int STDatatype;

// ��������ʵ�ֵķ�������top�����ջ��
typedef struct Stack
{
	STDatatype* a;//���Ƕ�̬���ݱ�
	//STDatatype a[MAX];//���Ǿ�̬���ݱ�

	int top;
	int capacity;
}ST;


//��ʼ��
void StackInit(ST* ps);

//����
void StackDestory(ST* ps);

//ѹջ
void StackPush(ST* ps, STDatatype x);

//��ջ
void StackPop(ST* ps );

//��ȡջ������
STDatatype StackTop(ST* ps);

//��ȡջ�����ݸ���
int StackSize(ST* ps);

//�ж�ջ�Ƿ�Ϊ�գ�1Ϊ�գ�0Ϊ�ǿ�
bool IsStackEmpty(ST* ps);