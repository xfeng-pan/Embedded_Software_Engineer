#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

typedef struct flexarr
{
	int a;
	int* arr;//���ָ��ָ��һ����̬���ٵ�����
}parr;

int main()
{
	//��̬����һ���ṹ��
	parr* ptr = (parr*)malloc(sizeof(parr));
	ptr->a = 5;
	//��̬��������ṹ���е�����
	ptr->arr = (int*)malloc(5 * sizeof(int));
	for (int i = 0; i < 5; i++)
	{
		ptr->arr[i] = i;
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", ptr->arr[i]);
	}

	//������С
	int* p = (int*)realloc(ptr->arr,10 * sizeof(int));
	if (NULL != p)
	{
		ptr->arr = p;
	}
	for (int i = 0; i < 10; i++)
	{
		ptr->arr[i] = i;
	}
	for (int i = 5; i < 10; i++)
	{
		printf("%d\n", ptr->arr[i]);
	}


	free(ptr->arr);
	ptr->arr = NULL;
	free(ptr);
	ptr = NULL;
	p = NULL;
	return 0;
}



//typedef struct flexarr
//{
//	int a;
//	int arr[];
//}farr;
//
//int main()
//{
//	int n = 5;
//	//��̬����һ���ռ䣬�ռ�Ĵ�Сͨ������Ҫ�Ĵ�С���м���
//	//��С��4+n*4=24
//	farr* p = (farr*)malloc(sizeof(int) + n * sizeof(int));
//	//��Ч�Լ��
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	p->a = n;
//	//�����ݸ�ֵ�����
//	for (int i = 0; i < n; i++)
//	{
//		p->arr[i] = i;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", p->arr[i]);
//	}
//	printf("\n");
//
//	n = 10;
//	//�ı������ٵĿռ�Ĵ�С
//	farr* ptr = realloc(p, sizeof(int) + n * sizeof(int));
//	if (NULL != ptr)//��Ч���ж�
//	{
//		p = ptr;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		p->arr[i] = i;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", p->arr[i]);
//	}
//	printf("\n");
//
//	//�ͷŶ�̬�ڴ�
//	free(p);
//	p = NULL;
//	ptr = NULL;
//
//	return 0;
//}


//struct s
//{
//	int a;
//	int arr[];//δ֪��С����������
//};
//
//struct ss
//{
//	int a;
//	int arr[0];//δ֪��С����������
//};
//
//int main()
//{
//	struct s s1;
//	struct ss s2;
//	return 0;
//}

//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//
//	free(str);
//	str = NULL;
//}
//
//int  main()
//{
//	Test();
//	return 0;
//}

//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//
//int  main()
//{
//	Test();
//	return 0;
//}

//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}

//int* test()
//{
//	int* ptr = (int*)malloc(100);
//	return ptr;//ptr�ᱻ���٣���malloc���ٵĿռ仹��
//}
//
//int main()
//{
//	int* p = test();
//	*p = 20;
//	printf("%d\n", *p);
//	return 0;
//}

// 
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//
//int main()
//{
//	int* p = test();
//	*p = 20;
//	printf("%d\n", *p);
//	return 0;
//}

//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}

//��Ŀ1��
// ����д��
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
//��ȷд����
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//	
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//
//	if (str != NULL)
//	{
//		strcpy(str, "hello world");
//		printf(str);
//		free(str);
//		str = NULL;
//	}
//	else
//	{
//		printf("%s\n", strerror(errno));
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}
//��ȷд��2��
//char* GetMemory(char* p)
//{
//	return p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	str=GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}


//#include <Windows.h>
//int main()
//{
//	while (1)
//	{
//		malloc(1);
//		//Sleep(1);
//	}
//}
//void test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL != p)
//	{
//		*p = 20;
//	}
//}
//int main()
//{
//	test();
//	while (1);
//}

//int main()
//{
//	int* p = (int*)malloc(100);
//	free(p);
//	free(p);//�ظ��ͷ�
//	return 0;
//}
//int main()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);//p����ָ��̬�ڴ����ʼλ��
//}

//
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);//ok?
//}

//int main()
//{
//	int* p = (int*)malloc(INT_MAX);
//	p = NULL;
//	*p = 20;//���p��ֵ��NULL���ͻ�������
//	free(p);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;//��i��10��ʱ��Խ�����
//	}
//	free(p);//����ᱨ��
//	p = NULL;
//	return 0;
//}
//int main()
//{
//	int num = 8;
//	int num2 = 2 * num;
//	int num3 = 3 * num*sizeof(int);
//	int* p = calloc(num, sizeof(int));
//
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < num; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//		printf("\n");
//	}
//
//	//realloc ��չ�ռ�
//	int* p2 = (int*)realloc(p, num3);
//	//free(p);
//	//p = NULL;
//	if (NULL != p2)
//	{
//		p = p2;
//		int i = 0;
//		for (i = 0; i < num2; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < num3; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//		printf("\n");
//		free(p2);
//		p = NULL;
//		p2 = NULL;
//	}
//	return 0;	
//}

//int main()
//{
//	//����8��int���͵Ŀռ�
//	int* p = (int*)calloc(8, sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n",strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 8; i++)
//		{
//			*(p+i) = i;
//		}
//		for (i = 0; i < 8; i++)
//		{
//			printf("%d ", *(p + i));
//		}				
//	}
//	//�ͷŶ�̬���ٵĿռ�
//	free(p);
//	//����ָ��
//	p = NULL;
//
//	return 0;
//}



//int main()
//{
//	//����һ���ܴ洢ʮ�����ͱ����Ŀռ�
//	int* p = (int*)  malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//�������٣����Կ�ʼʹ�ÿռ�
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//			printf("%d\n", *(p + i));
//		}
//	}
//	//����̬����Ŀռ䲻��ʹ���ˣ���Ҫ�ͷſռ�
//	//���ռ仹������ϵͳ
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//struct Student
//{
//	char arr[20];
//	int age;
//};
//
//int main()
//{
//	struct Student stu[50];
//	//������һ���ܴ洢50��ѧ����Ϣ������
//	return 0;
//}

////�䳤����
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n] = { 0 };
//
//}








