#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = (STDatatype*)malloc(4 * sizeof(STDatatype));
	ps->capacity = 4;
	ps->top = 0;
	// ��ʼtop = 0��topָ�����ջ������һ��Ԫ��
	// ��ʼtop = =1��topָ�����ջ����Ԫ��


}


void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;

}

 //���˾�����
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


//�⼸���������붼ֻ��һ���У����ǲ���ֱ��д�ڱ�ĺ������棬�������γ��˺���֮������
//�޷����������ھۣ�����ϵ�Ҫ��
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
	//0�Ƿǿգ�1�ǿ�
	return ps->top == 0;
}
