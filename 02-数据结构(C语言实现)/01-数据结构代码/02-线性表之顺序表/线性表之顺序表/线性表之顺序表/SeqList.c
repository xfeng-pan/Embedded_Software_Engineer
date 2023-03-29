#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//��̬˳���
//void SeqListInit(SL* ps)
//{
//	memset(ps->a, 0, MAX_SIZE * sizeof(SQDataType));
//	ps->size = 0;
//}

void SeqListInit(SL* ps)//��ʼ��
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}


//��ӡ
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\r\n");
}

void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		SQDataType* tmp = (SQDataType*)realloc(ps->a, newcapacity * sizeof(SQDataType));
		if (NULL == tmp)
		{
			printf("realloc failed!!!\r\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity = newcapacity;
		}
	}
}

//β������
void SeqListPushBack(SL* ps, SQDataType x)
{
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;

}

//ͷ������
void SeqListPushFront(SL* ps, SQDataType x)
{
	int end = ps->size - 1;

	SeqListCheckCapacity(ps);


	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;

	ps->size++;

}

//β��ɾ��
void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);

	ps->a[ps->size - 1] = 0;

	ps->size--;

}

//ͷ��ɾ��
void seqListPopFront(SL* ps)
{

}
