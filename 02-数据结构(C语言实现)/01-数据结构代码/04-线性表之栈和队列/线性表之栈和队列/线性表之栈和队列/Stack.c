#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = (STDatatype*)malloc(4 * sizeof(STDatatype));
	ps->capacity = 4;
	ps->top = 0;
	// 初始top = 0，top指向的是栈顶的下一个元素
	// 初始top = =1，top指向的是栈顶的元素


}


void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;

}

 //满了就增容
void StackCheck(ST* ps)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		STDatatype* tmp = (STDatatype*)realloc(ps->a, ps->capacity * sizeof(ST) * 2);
		if (tmp == NULL)
		{
			printf("realloc fail!!!\r\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity = 2 * ps->capacity;
		}

	}
}


void StackPush(ST* ps, STDatatype x)
{
	assert(ps);
	StackCheck(ps);
	ps->a[ps->top] = x;
	ps->top++;

}


void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top);
	ps->top--;

}


//这几个函数代码都只有一两行，但是不能直接写在别的函数里面，那样就形成了函数之间的耦合
//无法满足程序高内聚，低耦合的要求
STDatatype StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top);

	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool IsStackEmpty(ST* ps)
{
	//0是非空，1是空
	return ps->top == 0;
}
