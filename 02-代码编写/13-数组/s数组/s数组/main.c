#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);
	printf("%d\n", *arr);
	printf("%p \n", &arr+1);

	return 0;
}

//void bubble_sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz - 1; i++)//冒泡排序的趟数
//	{
//		int flag = 1;
//		for (int j = 0; j < sz - i - 1; j++)//实际比较排序
//		{
//			int tmp = 0;
//			if (arr[j] < arr[j + 1])//大于还是小于决定了这里是升序还是降序排列
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//			if (flag == 1) 
//			{
//				break;//数组已经是有序的了，提前跳出排序循环
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[10] = { 4,5,6,3,2,8,1,9,7,10 };
//	int sz = sizeof(arr) / sizeof(int);
//
//	bubble_sort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	int arr1[3][4] = { {1,2,3,4},{1,2,3},1 };
//	int arr2[3][4] = { 1,2,3,4,5,6 };
//	return 0;
//}

//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = {'a','b','c'};
//	printf("%lld\n", sizeof(arr1));//4
//	printf("%lld\n", sizeof(arr2));//3
//	printf("%lld\n", strlen(arr1));//3
//	printf("%lld\n", strlen(arr2));//随机数
//	return 0;
//}


//int main()
//{
//	char arr[] = "abcdefg";
//	printf("%lld\n", sizeof(arr));
//	printf("%lld\n", strlen(arr));
//	return 0;
//}
