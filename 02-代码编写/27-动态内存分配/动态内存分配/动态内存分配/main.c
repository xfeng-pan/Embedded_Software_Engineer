#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

typedef struct flexarr
{
	int a;
	int* arr;//这个指针指向一个动态开辟的数组
}parr;

int main()
{
	//动态开辟一个结构体
	parr* ptr = (parr*)malloc(sizeof(parr));
	ptr->a = 5;
	//动态开辟这个结构体中的数组
	ptr->arr = (int*)malloc(5 * sizeof(int));
	for (int i = 0; i < 5; i++)
	{
		ptr->arr[i] = i;
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", ptr->arr[i]);
	}

	//调整大小
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
//	//动态开辟一个空间，空间的大小通过所需要的大小进行计算
//	//大小：4+n*4=24
//	farr* p = (farr*)malloc(sizeof(int) + n * sizeof(int));
//	//有效性检测
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	p->a = n;
//	//对内容赋值并输出
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
//	//改变所开辟的空间的大小
//	farr* ptr = realloc(p, sizeof(int) + n * sizeof(int));
//	if (NULL != ptr)//有效性判断
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
//	//释放动态内存
//	free(p);
//	p = NULL;
//	ptr = NULL;
//
//	return 0;
//}


//struct s
//{
//	int a;
//	int arr[];//未知大小的柔性数组
//};
//
//struct ss
//{
//	int a;
//	int arr[0];//未知大小的柔性数组
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
//	return ptr;//ptr会被销毁，但malloc开辟的空间还在
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

//题目1：
// 错误写法
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
//正确写法；
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
//正确写法2；
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
//	free(p);//重复释放
//	return 0;
//}
//int main()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);//p不再指向动态内存的起始位置
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
//	*p = 20;//如果p的值是NULL，就会有问题
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
//		*(p + i) = i;//当i是10的时候越界访问
//	}
//	free(p);//这里会报错
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
//	//realloc 拓展空间
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
//	//开辟8个int类型的空间
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
//	//释放动态开辟的空间
//	free(p);
//	//重置指针
//	p = NULL;
//
//	return 0;
//}



//int main()
//{
//	//开辟一个能存储十个整型变量的空间
//	int* p = (int*)  malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//正常开辟，可以开始使用空间
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//			printf("%d\n", *(p + i));
//		}
//	}
//	//当动态申请的空间不再使用了，则要释放空间
//	//将空间还给操作系统
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
//	//创建了一个能存储50个学生信息的数组
//	return 0;
//}

////变长数组
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n] = { 0 };
//
//}








