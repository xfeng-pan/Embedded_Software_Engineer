#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

// 栈的两种实现方法：
// 1. 数组, 
// 2. 链表

//#define MAX 100;

typedef int STDatatype;

// 用数组来实现的方法：用top来标记栈顶
typedef struct Stack
{
	STDatatype* a;//这是动态数据表
	//STDatatype a[MAX];//这是静态数据表

	int top;
	int capacity;
}ST;


//初始化
void StackInit(ST* ps);

//销毁
void StackDestory(ST* ps);

//压栈
void StackPush(ST* ps, STDatatype x);

//出栈
void StackPop(ST* ps );

//读取栈顶数据
STDatatype StackTop(ST* ps);

//获取栈内数据个数
int StackSize(ST* ps);

//判断栈是否为空，1为空，0为非空
bool IsStackEmpty(ST* ps);