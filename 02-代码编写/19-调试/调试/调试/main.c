#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char*  my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);//¶ÏÑÔ
	assert(src != NULL);//¶ÏÑÔ
	
	while ((*dest) ? (*dest++ = *src++) : 0)
	{
		;
	}
	*dest = *src;
	return ret;
}

int main()
{
	//strcpy
	//×Ö·û´®¿½±´

	char arr1[] = "####################";
	char arr2[] = "hello world";
	char arr3[] = "my_strcpy";

	strcpy(arr1, arr2);
	printf("%s\n", arr1);
	printf("%s\n", arr2);

	

	printf("%s\n", arr1);
	printf("%s\n", my_strcpy(arr1, arr3));

	return 0;
}





//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		printf("%d ", i);
//		printf("hello world!\n");
//		arr[i] = 0;
//	}
//	system("pause");
//}

//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <10; i++)
//	{
//		printf("%d ", i);
//		printf("hello world!\n");
//		arr[i] = 0;
//	}
//	system("pause");
//}

//int main()
//{
//	int i = 0;
//	for (i = 0; i < 20; i++)
//	{
//		printf("%d\n", i);
//	}
//	system("pause");
//
//	return 0;
//}




