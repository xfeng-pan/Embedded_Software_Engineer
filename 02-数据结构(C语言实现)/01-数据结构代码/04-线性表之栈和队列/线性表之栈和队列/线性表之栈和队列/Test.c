#define _CRT_SECURE_NO_WARNINGS 1


#include "Stack.h"
#include "Queue.h"

//’ª≤‚ ‘
void StactTest(void)
{
	ST st;
	StackInit(&st);

	StackPush(&st, 0);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	while (!IsStackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\r\n");


	StackDestory(&st);
}


//∂”¡–≤‚ ‘
void QueueTest(void)
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 0);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (!IsQueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}

	printf("\r\n");
	

	QueueDestory(&q);

}

int main()
{
	StactTest();
	QueueTest();
	
	return 0;
}
