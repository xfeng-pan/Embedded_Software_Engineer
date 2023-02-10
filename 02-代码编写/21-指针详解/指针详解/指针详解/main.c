#define _CRT_SECURE_NO_WARNINGS 1

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));// 48 = 3 * 4 * 4 bytes
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));// 16 = 4 * 4 计算的是第一行的元素的大小
	printf("%d\n", sizeof(a[0]+1));//4 或 8 这是一个地址，指向的是第一行第二个元素
	printf("%d\n", sizeof(*(a[0]+1)));//4
	printf("%d\n", sizeof(a+1));//8
	printf("%d\n", sizeof(*(a+1)));//16
	printf("%d\n", sizeof(&a[0]+1));//4或8
	printf("%d\n", sizeof(*(&a[0] + 1)));//16
	printf("%d\n", sizeof(*a));//16
	printf("%d\n", sizeof(a[3]));//16 超出数组范围，err

	return 0;
}


//int main()
//{
//	char *p = "abcdef";
//	printf("%d\n", sizeof(p));//8
//	printf("%d\n", sizeof(p + 1));//8:arr是地址，地址往后移1位，还是地址，计算的是b的地址
//	printf("%d\n", sizeof(*p));//1:p指向的是a所在的地址
//	printf("%d\n", sizeof(p[1]));//1
//	printf("%d\n", sizeof(&p));//8
//	printf("%d\n", sizeof(&p + 1));//8 指向的内容不确定，是字符串后面的一位
//	printf("%d\n", sizeof(&p[0] + 1));//8
//
//	printf("%d\n", strlen(p));//6
//	printf("%d\n", strlen(p + 1));//5
//	//printf("%d\n", strlen(*p));//会访问97的地址，非法访问，错误代码
//	//printf("%d\n", strlen(p[0]));//会访问98的地址，非法访问，错误代码
//	printf("%d\n", strlen(&p));//6 会报错 理应是一个随机值 char **p=&arr,与strlen的传入参数 “const char”间接级别不同
//	printf("%d\n", strlen(&p + 1));//随机值
//	printf("%d\n", strlen(&p[0] + 1));//5
//
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", sizeof(arr));//7
//	printf("%d\n", sizeof(arr+0));//8:arr是地址，地址往后移0位，还是地址
//	printf("%d\n", sizeof(*arr));//1
//	printf("%d\n", sizeof(arr[1]));//1
//	printf("%d\n", sizeof(&arr));//8
//	printf("%d\n", sizeof(&arr+1));//8
//	printf("%d\n", sizeof(&arr[0]+1));//8
//
//	printf("%d\n", strlen(arr));//6
//	printf("%d\n", strlen(arr+0));//6
//	//printf("%d\n", strlen(*arr));//会访问97的地址，非法访问，错误代码
//	//printf("%d\n", strlen(arr[1]));//会访问98的地址，非法访问，错误代码
//	printf("%d\n", strlen(&arr));//6 会报错 char(*p)[7]=&arr,与strlen的传入参数 “const char”间接级别不同
//	printf("%d\n", strlen(&arr+1));//随机值
//	printf("%d\n", strlen(&arr[0]+1));//5
//
//	return 0;
//}

//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", strlen(arr));//大于6的随机值
//	printf("%d\n", strlen(arr+0));//大于6的随机值
//	//printf("%d\n", strlen(*arr));//会访问97的地址，非法访问，错误代码
//	//printf("%d\n", strlen(arr[1]));//会访问98的地址，非法访问，错误代码
//	printf("%d\n", strlen(&arr));//大于6的随机值
//	printf("%d\n", strlen(&arr+1));//随机值，比上一个随机值小6
//	printf("%d\n", strlen(&arr[0]+1));//大于5的随机值，比上一个随机值大5
//
//	return 0;
//}


//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	//x64架构下：
//	printf("%d\n", sizeof(arr));//6
//	printf("%d\n", sizeof(arr+0));//8:arr是地址，地址往后移0位，还是地址
//	printf("%d\n", sizeof(*arr));//1
//	printf("%d\n", sizeof(arr[1]));//1
//	printf("%d\n", sizeof(&arr));//8
//	printf("%d\n", sizeof(&arr+1));//8
//	printf("%d\n", sizeof(&arr[0]+1));//8
//
//	return 0;
//}

//int main()
//{
//	int a[] = { 1,2,3,4 };//x64架构下：
//	//对于数组而言，sizeof和&都是对整个数组进行计算，而其它情况下：
//	//数组名表示的才是首元素的地址
//	printf("%d\n", sizeof(a));//16
//	printf("%d\n", sizeof(a+0));//8:a是地址，地址往后移0位，还是地址
//	printf("%d\n", sizeof(*a));//4：a是数组首元素地址，解引用得到的是第一个元素
//	printf("%d\n", sizeof(a+1));//8：a是数组地址往后移一位，还是地址
//	printf("%d\n", sizeof(a[1]));//4
//	printf("%d\n", sizeof(&a));//8
//	printf("%d\n", sizeof(*&a));//16：对数组取地址再解引用，得到的还是地址
//	printf("%d\n", sizeof(&a+1));//8
//	printf("%d\n", sizeof(&a[0]));//8
//	printf("%d\n", sizeof(&a[0]+1));//8
//
//	return 0;
//}




////交换函数，用于交换两个元素的位置
////需要传入两个元素的地址以及地址所占用的内存大小，单位：字节
////一个字节一个字节的进行交换
//void swap(char* p1, char* p2, int width)
//{
//	int j = 0;
//	for (j = 0; j < width; j++)//一个字节一个字节的进行交换
//	{
//		char temp = *p1;//定义一个缓存变量
//		*p1 = *p2;
//		*p2 = temp;//进行交换
//		p1++;
//		p2++;//交换下一个字节
//	}
//}
//
////比较函数的实现，程序员知道自己需要比较的是什么类型
////然后手写这个函数
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
////冒泡排序函数的实现
//void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	//进行sz-1趟冒泡排序
//	for (i = 0; i < sz-1; i++)
//	{
//		int ii = 0;
//		//每一趟冒泡排序需要该元素进行sz-i-1次比较排序
//		for (ii = 0; ii < sz - i - 1; ii++)
//		{
//			//cmp是比较函数，需要自己实现，当cmp的返回值>0时，说明第一个元素比较大。
//			if (cmp((char*)base + ii * width, (char*)base + (ii + 1) * width) > 0)
//				//如果确定了第一个元素比较大，则交换两个元素的位置
//				swap((char*)base + ii * width, (char*)base + (ii + 1) * width, width);
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };//数组定义
//	int sz = sizeof(arr) / sizeof(int);//计算数组的大小
//	bubble_sort(arr, sz, sizeof(int), cmp_int);//qsort的模仿实现
//	for (int index = 0; index < sz; index++)//打印排序之后的数组arr
//	{
//		printf("%d ", arr[index]);
//	}
//	printf("\n");
//	return 0;
//}
//










//int cmp_int(const void* e1, const void* e2)
//{
//	return (*(int*)e1 - *(int*)e2);
//}
//
//void test1(void)
//{
//	int arr[] = { 1,2,5,3,4,6,8,7,9,10 };
//	int sz = sizeof(arr) / sizeof(int);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int cmp_float(const void* e1, const void* e2)
//{
//	if (*(float*)e1 == *(float*)e2)
//	{
//		return 0;
//	}
//	else if (*(float*)e1 > *(float*)e2)
//	{
//		return 1;
//	}
//	else
//		return -1;
//}
//
//void test2(void)
//{
//	float arr2[] = { 1.0,2.5,5.0,3.0,6.1 };
//	int sz2 = sizeof(arr2) / sizeof(float);
//	qsort(arr2, sz2, sizeof(arr2[0]), cmp_float);
//	for (int i = 0; i < sz2; i++)
//	{
//		printf("%.2f ", arr2[i]);
//	}
//	printf("\n");
//}
//
//struct stu
//{
//	char name[20];
//	int age;
//};
//
//int cmp_struct_age(const void* e1, const void* e2)
//{
//	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
//}
//
//void test3()
//{
//	struct stu s[3] = { {"zhangsan",15},{"lisi",20},{"wangwu",17} };
//	int sz3 = sizeof(s) / sizeof(struct stu);
//	qsort(s, sz3, sizeof(struct stu), cmp_struct_age);
//	for (int i = 0; i < sz3; i++)
//	{
//		printf("%d ", s[i].age);
//	}
//	printf("\n");
//}
//
//int cmp_struct_name(const void* e1, const void* e2)
//{
//	return strcmp( ((struct stu*)e1)->name, ((struct stu*)e2)->name );
//}
//
//void test4(void)
//{
//	struct stu s[3] = { {"zhangsan",15},{"lisi",20},{"wangwu",17} };
//	int sz3 = sizeof(s) / sizeof(struct stu);
//	qsort(s, sz3, sizeof(struct stu), cmp_struct_name);
//	for (int i = 0; i < sz3; i++)
//	{
//		printf("%s \n", s[i].name);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	/*test1();*/
//	//test2();
//	//test3();
//	test4();
//	//test5();
//	return 0;
//}

//冒泡函数
//void bubble_sort(int arr[], int sz)
//{
//	int flag = 1;
//	for (int i = 0; i < sz - 1; i++)
//	{
//		int temp = 0;
//		for (int j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//				flag = 0;
//			}
//		}
//		if (1 == flag)
//			break;
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,5,3,4,6,8,7,9,10 };
//	int sz = sizeof(arr) / sizeof(int);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	bubble_sort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}


//int add(int a, int b)
//{
//	return a + b;
//}
//
//int sub(int a, int b)
//{
//	return a - b;
//}
//
//int mul(int a, int b)
//{
//	return a * b;
//}
//
//int div(int a, int b)
//{
//	return a / b;
//}
//
//int xor(int a, int b)
//{
//	return a ^ b;
//}
//
//void menu()
//{
//	printf("************************************\n");
//	printf("****** 1.add       2.sub  **********\n");
//	printf("****** 3.mul       4.div  **********\n");
//	printf("****** 5.xor       0.exit **********\n");
//	printf("************************************\n");
//}
//
//int main()
//{
//	int input = 0;
//	int a = 0;
//	int b = 0;
//	int (*parr[])(int, int) = {0,add,sub,mul,div,xor };
//	do
//	{
//		menu();
//		printf("请选择计算器功能：->\n");
//		scanf("%d", &input);
//		if (input > 0 && input < sizeof(parr))
//		{
//			printf("请输入两个操作数：->\n");
//			scanf("%d%d", &a, &b);
//			printf("%d\n", parr[input](a, b));
//		}
//		else if (0 == input)
//		{
//			printf("退出\n");
//		}
//		else
//		{
//			printf("输入错误，请重新输入：\n");
//		}
//	} while (input);
//}


//char* my_strcpy(char* dest,const char* src);
//
//char* (*pf)(char* , const char*)=my_strcpy;
//
//char* (*pfarr[4])(char*, const char*) = { my_strcpy ,my_strcpy ,my_strcpy ,my_strcpy };



//int add(int a, int b)
//{
//	return a + b;
//}
//
//int sub(int a, int b)
//{
//	return a - b;
//}
//
//int mul(int a, int b)
//{
//	return a * b;
//}
//
//int div(int a, int b)
//{
//	return a / b;
//}
//
//int main()
//{
//	int (*parr[])(int, int) = { add,sub,mul,div };
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d \n", parr[i](3, 2));//5,5,1,1,6,6,1,1
//		printf("%d \n", (*(parr+i))(3,2));
//	}
//}

//int add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int (*p)(int, int) = add;
//	//int (*p)(int, int) = &add;
//	printf("%d \n", (p)(2, 3));
//	printf("%d \n", (*p)(2, 3));
//	printf("%d \n", (**p)(2, 3));
//	printf("%d \n", (***p)(2, 3));
//	return 0;
//}


//void print(char* str)
//{
//	printf("%s", str);
//}
//
//int main()
//{
//	void (*p)(char*) = print;
//	(*p)("Hello, world!!!");
//}

//int add(int x, int y)
//{
//	return x + y;
//}
//
//char word(char i)
//{
//	return i + 1;
//}
//
//int main()
//{
//	int (*pa)(int, int) = &add;
//	char (*ch)(char) = &word;
//	printf("%d\n", (*pa)(2, 3));
//	printf("%c\n", (*ch)('a'));
//}

//int main()
//{
//	long a = 0x071f;
//	printf("%ld\n", a);
//
//	return 0;
//}

//void printarr(int(*pa)[5], int x, int  y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", *(*(pa + i) + j));
//			printf("%d ", (*(pa + i))[j]);
//			printf("%d ", pa[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5}, {2,3,4,5,6}, {3,4,5,6,7} };
//	printarr(arr, 3, 5);
//	return 0;
//}

//void printarr(int(*pa)[5], int x,int  y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", *(*(pa+i)+j));
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5}, {2,3,4,5,6}, {3,4,5,6,7} };
//	printarr(arr, 3, 5);
//	return 0;
//}


//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };
//
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int a = 0, b = 0, c = 0, d = 0;
//	int* arr [4] = {&a,&b,&c,&d};
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };//整型数组
//	char ch[5] = { 0 };//字符数组
//	int* parr[10] = { NULL };//是用来存放int指针的数组-指针数组
//	char* pch[5] = { NULL };//是用来存放char指针的数组-指针数组
//}

//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//
//	char* p1 = "abcdef";
//	char* p2 = "abcdef";
//
//	if (p1==p2)
//	{
//		printf("1");
//	}
//	else
//		printf("2");
//
//	return 0;
//}


//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//
//	char* p1 = "abcdef";
//	char* p2 = "abcdef";
//
//	if (arr1 == arr2)
//	{
//		printf("1");
//	}
//	else
//		printf("2");
//
//	return 0;
//}

//int main()
//{
//	const char* p = "abcdef";
//	*p = 'W';
//	//这是一个常量字符串
//	//p存储的是字符串的首地址
//	printf("%c\n", *p);
//	printf("%s\n", p);
//
//	return 0;
//}

//int main()
//{
//	char* p = "abcdef";
//	//这是一个常量字符串
//	//p存储的是字符串的首地址
//	printf("%c\n", *p);
//	printf("%s\n", p);
//
//	return 0;
//}


