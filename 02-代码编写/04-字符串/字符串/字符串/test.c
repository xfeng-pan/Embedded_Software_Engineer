#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int main()
//{
//	char arr1[] = "abc";
//	//char arr2[] = { 'a','b','c' ,'\0'};//两种写法都可以
//	//char arr2[] = { 97,'b','c' ,0};//97是a的ASCII编码
//	char arr2[] = { 97,'b','c' };//97是a的ASCII编码
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);//当arr2没有字符串结束标志的时候，会输出乱码
//	printf("%d\n", strlen(arr2));
//	printf("%c\n", '\132');
//
//
//	return 0;
//


//int main()
//{
//	int input = 0;
//	printf("今天你学习了么？\n");
//	printf("学了？没学？（1/0）:");
//	scanf("%d", &input);
//	if (input == 1)
//	{
//		printf("不错，继续努力\n");
//	}
//	else if(input == 0)
//	{
//		printf("快去学习\n");
//	}
//	else
//	{
//		printf("输入错误\n");
//	}
//
//}


int main()
{
	int index = 0;
	while (index <=10)
	{
		printf("index=%d\n", index);
		index++;
	}
	return 0;
}