#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
again:
	printf("Hello world\n");
	goto again;
}


//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//
//
//void game()
//{
//	int randnum = rand() % 100 + 1;
//	int ret = 0;
//	
//	while(1)
//	{
//		printf("请输入您猜的数字：>");
//		scanf("%d", &ret);
//		if (ret < randnum)
//			printf("猜小了\n");
//		else if (ret > randnum)
//			printf("猜大了\n");
//		else
//		{
//			printf("猜测正确!!!\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	//拿时间戳来设置随机数种子
//	//time_t time(time_t *timer); 获取系统时间，需要调用库函数time.h
//	//void srand(unsigned int seeed);需要调用库函数stdlib.h
//	srand ((unsigned int) time(NULL));
//
//	do
//	{
//		printf("*************************************\n");
//		printf("*******1.play       0.exit **********\n");
//		printf("*************************************\n");
//		scanf("%d", &input);
//		if (1 == input)
//			game();
//		else if (0 == input)
//			break;
//		else
//			printf("输入错误！\n");
//	} while (input);
//	printf("退出游戏！\n");
//	return 0;
//}






//#include <string.h>
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码：>");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("登陆成功\n");
//			break;
//		}
//		else
//			printf("密码错误\n");
//	}
//	if (i == 3)
//		printf("三次密码均错误！！！\n");
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <windows.h>
//#include <stdlib.h>
//int main()
//{
//	char arr[] = "Welcome to here!!!" ;
//	//int index = sizeof(arr) / sizeof(arr[0])-2;
//	int index = strlen(arr) - 1;//用这个来计算字符串长度从而得出数组的大小
//	char arr2[19] = { '\0' };
//
//	for (int i = 0; i < index; i++)
//	{
//		arr2[i] = '#';
//	}
//
//	for (int i = 0; i <= index / 2+1; i++)
//	{
//		Sleep(1000);
//		system("cls");
//		for (int j = 0; j < index; j++)
//		{
//			printf("%c", arr2[j]);
//		}
//		arr2[i] = arr[i];
//		arr2[index - i] = arr[index - i];
//		}
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("%d",sz);
//	return 0;
//}

//int binserach(int x, int arr[],int sz1)
//{
//	int left = 0;//数组下标，左值
//	int right = sz1;//数组下标，右值
//	int mid = (left + right) / 2; //数组下标，中值
//
//	while (x!=arr[mid])
//	{
//		if (x < arr[mid])
//		{
//			right = mid;
//			mid = (left + right) / 2;
//		}
//		else if (x > arr[mid])
//		{
//			left = mid;
//			mid = (left + right) / 2;
//		}
//		else
//			printf("err!!!\n");
//	}
//	if(x==arr[mid])
//		return mid;
//}
//
//int main()
//{
//	int arrs[] = { 1,2,3,4,5,6,7,8,9,10 };//待查找的数组
//	int n;//待查找的数，待用户输入；
//	int ret;//返回的结果下标
//	int sz = sizeof(arrs) / sizeof(arrs[0]);//计算数组的大小
//	printf("请输入带查找的数值：");
//	scanf("%d", &n);
//	ret = binserach(n, arrs,sz);
//	printf("%d是数组中的第%d位数", n, ret + 1);
//	return 0;
//}

//int binserach(int x, int arr[], int n)
//{
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		if (arr[i-1] == x)
//		{
//			printf("%d是数组中的第%d个元素\n", x, i);
//			break;
//		}
//	}
//	if (i > n)
//		printf("找不到\n");
//}
//
//int main()
//{
//	int n=20;
//	int x = 0;
//	int arr[20] = { 1,2,3,4,5,6,7,8,9,10,12,14,16,18,20,22,24,26,28,30 };
//	printf("请输入一个值：");
//	scanf("%d", &x);
//	binserach(x, arr, n);
//	return 0;
//}



//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	long long  sum = 0;
//	int max = 10;
//	long long  pro = 1;
//	
//	for (i = 1; i <= max; i++)
//	{
//		pro *= i;
//		sum += pro;
//	}
//	printf("%lld", sum);
//	return 0;
//}

//int main()
//{
//	int n;
//	long long result=1;
//	int i = 0;
//	printf("计算n的阶乘\n");
//	printf("请输入n：");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//		result *= i;
//	printf("n的阶乘是%lld\n", result);
//}

//int main()
//{
//	int i = 0;
//	do
//	{
//		i++;
//		if (i == 4)
//			continue;
//		if (i == 8)
//			break;
//		printf("%d ", i);
//		
//	}
//	while (i <= 10);
//	return 0;
//}

//int main()
//{
//	int i = 0, k = 0;
//	for (i = 0, k = 0; k = 0; i++, k++)
//		k++;
//	return 0;
//}

//int main()
//{
//	int x, y;
//	for (x = 0, y = 0; x < 2 && y < 5; x++, y++)
//	{
//		printf("x=%d,y=%d\n", x, y);
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (; i < 10; i++)
//	{
//		for (; j < 10; j++)
//			printf("循环打印ing\n");
//	}
//	return 0;
//}


//int main()
//{
//	for (;;)
//	{
//		printf("死循环\n");
//	}
//}


//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i == 8)
//			break;
//		if (i == 4)
//			continue;
//		printf("%d\n", i);
//	}
//	return 0;
//}




//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch>'9')
//			continue;
//		putchar(ch);
//	}
//}


//int main()
//{
//	int ret = 0;
//	char password[20] = { 0 };
//	printf("请输入密码->:");
//	scanf("%s", password);
//	//输入缓冲区还剩一个'\n'，其ACSII编码为10
//	//清空输入缓冲区
//	while ((ret = getchar()) != '\n')
//	{
//		;//空语句，不做任何事情
//	}
//
//	printf("请确认(Y/N)->:");
//	ret = getchar();
//	if (ret == 'Y')
//		printf("确认成功！");
//	else
//		printf("放弃失败！");
//	return 0;
//}



//int main()
//{
//	int ch = 0;
//	//EOF : end of file 文件结束标志
//	//本质是-1
//	//键盘输入：Ctrl+Z
//
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//	return 0;
//}