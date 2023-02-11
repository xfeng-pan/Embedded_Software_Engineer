#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		printf("open file success!!!\n");
	}
	return 0;	
}







//char* strtok(char* str, const char* sep);

//int main()
//{
//	char arr1[] = "qazwsx123@qq.com.cn";
//	char* p = "@..";
//
//	char buf[20] = { 0 };
//
//	strcpy(buf, arr1);
//
//	//切割buf中的数据
//	for (char* ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}

//int main()
//{
//	char arr1[] = "qazwsx123@qq.com.cn";
//	char* p = "@..";
//
//	char buf[20] = { 0 };
//
//	strcpy(buf, arr1);
//
//	//切割buf中的数据
//	char* ret=strtok(buf, p);
//
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);
//
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);
//
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);
//
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);
//
//	printf("%s\n", ret);
//
//	return 0;
//}

//char* my_strstr(const char* str1, const char* str2)
//{
//	char* s1 = (char *)str1;
//	char* s2 = (char *)str2;
//	char* cur = (char *)str1;//轮询查找
//
//	if (!*str1)
//		return s1;//要查找的字符串为空，则返回被查找的字符串
//
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = (char*)str2;
//		while (*s1 && *s2 && (*s1 == *s2))//对应字符相同，且不为空
//		{
//			s1++;
//			s2++;
//		}
//		if (!*s2)
//			return cur;//已经完成了查找
//		if (!*s1)
//			return NULL;//s1已经到头了，提前结束
//		cur++;
//	}
//	return NULL;
//
//}
//
//
//int main()
//{
//	const char* p1 = "abcdefg";
//	const char* p2 = "cdf";
//
//	char* ret = my_strstr(p1, p2);
//
//	if (ret == NULL) printf("未找到该字符串\n");
//	else printf("%s\n", ret);
//
//	return 0;
//}




////int srtncmp(const char* str1,const char* str2,int count)
////模拟实现：
//
//int my_strncmp(const char* str1, const char* str2, int count)
//{
//	assert(str1 && str2);
//	while (count-- && (*str1) && (*str2))
//	{
//		if (*str1 == *str2)
//		{
//			str1++;
//			str2++;
//		}
//		
//	}
//	return (*str1 - *str2);
//}
//
//
//int main()
//{
//	//strncmp-字符串比较
//	const char* p1 = "abcdefg";
//	const char* p2 = "aqwer";
//
//	//int ret = strcmp(p1, p2);
//	int ret = my_strncmp(p1, p2,3);
//	printf("%d\n", ret);
//
//	return 0;
//}

//char* my_strncat(char* dest, const char* src,int count)
//{
//	char* ret = dest;
//	assert(dest && src);
//	while (*dest)
//	{
//		dest++;
//	}
//	while (count-- && *src)
//	{
//		*dest++ = *src++;
//	}
//	*dest = '\0';
//	return ret;
//}
//
//int main()
//{
//	char arr1[30] = "abcdefg\0xxxxxxxxxxxxxxxxx";
//	char arr2[] = "hello world!!!";
//
//	my_strncat(arr1, arr2, 6);
//	printf("%s\n", arr1);
//
//	return 0;
//}

//char* my_strncpy(char* dest, const char* src,int count)
//{
//	char* ret = dest;
//	assert(dest && src);
//	while (count--)
//	{
//		if (*src != '\0')
//		{
//			*dest++ = *src++;
//		}
//		else *dest++ = '\0';
//	}
//	return ret;	
//}
//
//int main()
//{
//	char arr1[10] = "abcdefg";
//	char arr2[] = "he";
//
//	my_strncpy(arr1, arr2, 4);
//
//	printf("%s\n", arr1);
//	
//	return 0;
//}

//my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	//比较
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0') return 0;
//		str1++;
//		str2++;
//	}
//	return (*str1 - *str2);
//}
//
//int main()
//{
//	char* p1 = "abc";
//	char* p2 = "qc";
//	int ret = my_strcmp(p1, p2);
//	printf("%d\n",ret);
//	return 0;
//}


//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = "acb";
//	int ret = strcmp(arr1, arr2);
//	printf("%d\n", ret);
//	return 0;
//}


//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	//1.寻找dest的结尾：
//	while (*dest!='\0')
//	{
//		dest++;
//	}
//	//2.追加
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[30] = "hello \0xxxxxxx";
//	char arr2[] = "world!!!`";
//
//	my_strcat(arr1, arr2);
//
//	printf("%s\n", arr1);
//
//	return 0;
//}

//char* my_strcpy(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest != NULL);//断言
//	assert(src != NULL);//断言
//	//字符串拷贝
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	
//	return ret;
//}
//
//int main()
//{
//	//strcpy
//	//字符串拷贝
//
//	char arr1[] = "####################";
//	char arr2[] = "hello world";
//	char arr3[] = "my_strcpy";
//
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//
//
//
//	printf("%s\n", arr1);
//	printf("%s\n", my_strcpy(arr1, arr3));
//
//	return 0;
//}


//int my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*str != '\0')
//	{
//		if (*dest != '\0')
//		{
//			*dest = *str;
//			des++;
//			str++;
//		}
//		else
//			break;
//	}
//
//}
//
//int main()
//{
//	char arr1[] = "abcdefghijk";
//	char arr2[] = "pxf";
//
//	my_strcpy(arr1, arr2);
//
//	printf("%s\n", arr1);
//	
//	return 0;
//}


//计数器
//int my_strlen(const char* str)//size_t
//{
//	int count = 0;
//	assert(str != NULL);
//
//	while ('\0' != *str)//while(*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}


//递归

//int my_strlen(const char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}

//指针-指针



//int main()
//{
//	printf("%d\n", my_strlen("abcdef"));
//
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf("abc\n");
//	}
//	else
//	{
//		printf("abcdef\n");
//	}
//	return 0;
//}

//int main()
//{
//	char arr1[] = { 'a','b','c' ,'\0' };
//	char arr2[] = { 'a','b','c'};
//
//	printf("%d\n", strlen("abc"));
//	printf("%d\n", strlen(arr1));
//	printf("%d\n", strlen(arr2));//直到找到'\0'才停止
//
//	return 0;
//}




