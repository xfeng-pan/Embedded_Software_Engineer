#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8 };
	//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 ...
	int arr2[] = { 1,2,3,4,6,5,7,8 };
	//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 06 ...
	int ret = memcmp(arr1, arr2,4*5);

	printf("%d\n", ret);

	return 0;
}




//void* my_memmove(void* dest, const void* src, int count)
//{
//	void* ret = dest;
//	assert(dest && src);
//	if (dest < src)
//	{
//		//从前到后
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else
//	{
//		//从后到前
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}	
//	return ret;
//}
//
//int  main()
//{
//	int arr[20] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	my_memmove(arr, arr + 2, sizeof(int) * 5);
//
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}




//void* my_memcpy(void* dest, const void* src, int count)
//{
//	void* ret = dest;
//	assert(dest && src);
//	while (count--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return ret;
//}
//
//int  main()
//{
//	int arr[20] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memcpy(arr + 2, arr, sizeof(int) * 5);
//
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//
//}


//struct stu
//{
//	char name[20];
//	int age;
//};

//void* my_memcpy(void* dest, const void* src, int count)
//{
//	void* ret = dest;
//	assert(dest && src);
//	while (count--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return ret;
//}

//int main()
//{
//	struct stu arr1[] = { {"example1",18},{"example2",22} };
//	struct stu arr2[3] = { 0 };
//	my_memcpy(arr2, arr1, sizeof(arr1));
//
//	return 0;
//}


//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	memcpy(arr2, arr1, sizeof(arr1));
//	return 0;
//}



//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	strcpy(arr2, arr1);
//	return 0;
//}

