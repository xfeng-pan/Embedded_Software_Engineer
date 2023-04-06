#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;

typedef struct Stack
{
    QDataType* arr;
    int top;
    int capacity;
}Stack;

void StackInit(Stack* ps)
{
    assert(ps);
    QDataType* tmp = (QDataType*)malloc(4 * sizeof(QDataType));
    if (tmp == NULL)
    {
        printf("malloc failed");
        exit(-1);
    }
    ps->arr = tmp;
    ps->top = 0;
    ps->capacity = 4;
}

void StackDestory(Stack* ps)
{
    assert(ps);
    free(ps->arr);
    ps->arr = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

void StackCheck(Stack* ps)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        QDataType* tmp = (QDataType*)realloc(ps->arr, 2 * ps->capacity * sizeof(QDataType));
        if (tmp == NULL)
        {
            printf("realloc failed!!!\r\n");
            exit(-1);
        }
        ps->arr = tmp;
        ps->capacity *= 2;
    }
}

void StackPush(Stack* ps, QDataType x)
{
    assert(ps);
    StackCheck(ps);
    ps->arr[ps->top] = x;
    ps->top++;
}

QDataType StackPop(Stack* ps)
{
    assert(ps);
    assert(ps->top > 0);
    QDataType ret = ps->arr[ps->top - 1];
    ps->top--;
    return ret;
}

QDataType StackTop(Stack* ps)
{
    assert(ps);
    assert(ps->top > 0);
    return ps->arr[ps->top - 1];
}

int StackSize(Stack* ps)
{
    return ps->top;
}

//1£º¿Õ 0£º·Ç¿Õ
bool IsStackEmpty(Stack* ps)
{
    assert(ps);
    return ps->top == 0;
}



typedef struct {
    Stack stackpush;
    Stack stackpop;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
    if (mq == NULL)
    {
        printf("mq malloc failed\r\n");
        exit(-1);
    }
    StackInit(&(mq->stackpush));
    StackInit(&(mq->stackpop));
    return mq;
}

void myQueuePush(MyQueue* obj, int x) {
    assert(obj);
    StackPush(&(obj->stackpush), x);
}

int myQueuePop(MyQueue* obj) {
    assert(obj);
    if (IsStackEmpty(&(obj->stackpop)))
    {
        while (!IsStackEmpty(&(obj->stackpush)))
        {
            QDataType tmp = StackPop(&(obj->stackpush));
            StackPush(&(obj->stackpop), tmp);
        }
    }
    int ret = StackPop(&(obj->stackpop));
    return ret;
}

int myQueuePeek(MyQueue* obj) {
    assert(obj);
    if (IsStackEmpty(&(obj->stackpop)) == 1)
    {
        while (!IsStackEmpty(&(obj->stackpush)))
        {
            QDataType tmp = StackPop(&(obj->stackpush));
            StackPush(&(obj->stackpop), tmp);
        }
    }
    return StackTop(&(obj->stackpop));

}

bool myQueueEmpty(MyQueue* obj) {
    assert(obj);
    return IsStackEmpty(&(obj->stackpop)) && IsStackEmpty(&(obj->stackpush));
}

void myQueueFree(MyQueue* obj) {
    assert(obj);
    free(obj->stackpop.arr);
    free(obj->stackpush.arr);
    free(obj);
    obj = NULL;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/


int main()
{
    MyQueue* mq = myQueueCreate();
    myQueuePush(mq, 1);
  //  myQueuePush(mq, 2);
  // printf("%d \r\n", myQueuePeek(mq));
    printf("%d \r\n", myQueuePop(mq));
    printf("%d \r\n", myQueueEmpty(mq));

    myQueueFree(mq);

    printf("working ending\r\n");

    return 0;
}