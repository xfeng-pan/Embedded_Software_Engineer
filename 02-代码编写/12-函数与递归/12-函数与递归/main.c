#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[20] = "Hello";
//	int n = 0;
//	n = my_strlen(arr);
//	printf("%d\n",n);
//	return 0;
//}

//void printnum(int n)
//{
//	if (n > 9)
//		printnum(n / 10);
//	printf("%d ", n % 10); 
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printnum(n);
//	return 0;
//}

//int main()
//{
//	printf("Hello\n");
//	main();
//	return 0;
//}

//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));
//	return 0;
//}


//void swap(int* x, int* y)
//{
//	int temp = 0;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//
//}
//
//int main()
//{
//	int a = 10, b = 20;
//	printf("a=%d b=%d\n", a, b);
//	swap(&a, &b);
//	printf("a=%d b=%d\n", a, b);
//	return 0;
//}




//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str[] = "almost every programmer should know memset!";
//	memset(str, '-', 6);
//	puts(str);
//	return 0;
//
//}


//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char arr1[] = "hello";
//	char arr2[20] = "###############";
//	strcpy(arr2, arr1);
//	//此时arr2=“hello\0########”,但是o后面有结束符号，所以输出的时候不会打印#
//	printf("%s\n", arr2);
//	return 0;
//}