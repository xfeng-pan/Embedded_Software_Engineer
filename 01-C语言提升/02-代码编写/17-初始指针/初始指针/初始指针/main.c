#include <stdio.h>

int main()
{
	int a = 0;
	int b = 1;
	int c = 2;
	int* arr[3] = { &a,&b,&c };
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", *(arr[i]));
	}
		return 0;
}


//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int** ppa = &pa;
//
//	return 0;
//}



//int main()
//{
//	int arr[10]= { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);
//
//	return 0;
//}

//int my_strlen(char* str)
//{
//	char* start = str;
//	char* end = str;
//
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - start;
//}
//
//int main()
//{
//	char arr[] = "hello world!";
//	printf("%d\n", my_strlen(arr));
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d\n", &arr[9] - &arr[0]+1);
//	return 0;
//}




//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(int);
//	int* p = arr;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *p);
//		p = p + 1;
//	}
//}



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
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i <= 11; i++)
//	{
//		*(p++) = i;
//	}
//	return 0;
//}



//int main()
//{
//	int* p;
//	*p = 20;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* p = &a;
//	return 0;
//}