#define _CRT_SECURE_NO_WARNINGS 1

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));// 48 = 3 * 4 * 4 bytes
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));// 16 = 4 * 4 ������ǵ�һ�е�Ԫ�صĴ�С
	printf("%d\n", sizeof(a[0]+1));//4 �� 8 ����һ����ַ��ָ����ǵ�һ�еڶ���Ԫ��
	printf("%d\n", sizeof(*(a[0]+1)));//4
	printf("%d\n", sizeof(a+1));//8
	printf("%d\n", sizeof(*(a+1)));//16
	printf("%d\n", sizeof(&a[0]+1));//4��8
	printf("%d\n", sizeof(*(&a[0] + 1)));//16
	printf("%d\n", sizeof(*a));//16
	printf("%d\n", sizeof(a[3]));//16 �������鷶Χ��err

	return 0;
}


//int main()
//{
//	char *p = "abcdef";
//	printf("%d\n", sizeof(p));//8
//	printf("%d\n", sizeof(p + 1));//8:arr�ǵ�ַ����ַ������1λ�����ǵ�ַ���������b�ĵ�ַ
//	printf("%d\n", sizeof(*p));//1:pָ�����a���ڵĵ�ַ
//	printf("%d\n", sizeof(p[1]));//1
//	printf("%d\n", sizeof(&p));//8
//	printf("%d\n", sizeof(&p + 1));//8 ָ������ݲ�ȷ�������ַ��������һλ
//	printf("%d\n", sizeof(&p[0] + 1));//8
//
//	printf("%d\n", strlen(p));//6
//	printf("%d\n", strlen(p + 1));//5
//	//printf("%d\n", strlen(*p));//�����97�ĵ�ַ���Ƿ����ʣ��������
//	//printf("%d\n", strlen(p[0]));//�����98�ĵ�ַ���Ƿ����ʣ��������
//	printf("%d\n", strlen(&p));//6 �ᱨ�� ��Ӧ��һ�����ֵ char **p=&arr,��strlen�Ĵ������ ��const char����Ӽ���ͬ
//	printf("%d\n", strlen(&p + 1));//���ֵ
//	printf("%d\n", strlen(&p[0] + 1));//5
//
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", sizeof(arr));//7
//	printf("%d\n", sizeof(arr+0));//8:arr�ǵ�ַ����ַ������0λ�����ǵ�ַ
//	printf("%d\n", sizeof(*arr));//1
//	printf("%d\n", sizeof(arr[1]));//1
//	printf("%d\n", sizeof(&arr));//8
//	printf("%d\n", sizeof(&arr+1));//8
//	printf("%d\n", sizeof(&arr[0]+1));//8
//
//	printf("%d\n", strlen(arr));//6
//	printf("%d\n", strlen(arr+0));//6
//	//printf("%d\n", strlen(*arr));//�����97�ĵ�ַ���Ƿ����ʣ��������
//	//printf("%d\n", strlen(arr[1]));//�����98�ĵ�ַ���Ƿ����ʣ��������
//	printf("%d\n", strlen(&arr));//6 �ᱨ�� char(*p)[7]=&arr,��strlen�Ĵ������ ��const char����Ӽ���ͬ
//	printf("%d\n", strlen(&arr+1));//���ֵ
//	printf("%d\n", strlen(&arr[0]+1));//5
//
//	return 0;
//}

//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", strlen(arr));//����6�����ֵ
//	printf("%d\n", strlen(arr+0));//����6�����ֵ
//	//printf("%d\n", strlen(*arr));//�����97�ĵ�ַ���Ƿ����ʣ��������
//	//printf("%d\n", strlen(arr[1]));//�����98�ĵ�ַ���Ƿ����ʣ��������
//	printf("%d\n", strlen(&arr));//����6�����ֵ
//	printf("%d\n", strlen(&arr+1));//���ֵ������һ�����ֵС6
//	printf("%d\n", strlen(&arr[0]+1));//����5�����ֵ������һ�����ֵ��5
//
//	return 0;
//}


//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	//x64�ܹ��£�
//	printf("%d\n", sizeof(arr));//6
//	printf("%d\n", sizeof(arr+0));//8:arr�ǵ�ַ����ַ������0λ�����ǵ�ַ
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
//	int a[] = { 1,2,3,4 };//x64�ܹ��£�
//	//����������ԣ�sizeof��&���Ƕ�����������м��㣬����������£�
//	//��������ʾ�Ĳ�����Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(a));//16
//	printf("%d\n", sizeof(a+0));//8:a�ǵ�ַ����ַ������0λ�����ǵ�ַ
//	printf("%d\n", sizeof(*a));//4��a��������Ԫ�ص�ַ�������õõ����ǵ�һ��Ԫ��
//	printf("%d\n", sizeof(a+1));//8��a�������ַ������һλ�����ǵ�ַ
//	printf("%d\n", sizeof(a[1]));//4
//	printf("%d\n", sizeof(&a));//8
//	printf("%d\n", sizeof(*&a));//16��������ȡ��ַ�ٽ����ã��õ��Ļ��ǵ�ַ
//	printf("%d\n", sizeof(&a+1));//8
//	printf("%d\n", sizeof(&a[0]));//8
//	printf("%d\n", sizeof(&a[0]+1));//8
//
//	return 0;
//}




////�������������ڽ�������Ԫ�ص�λ��
////��Ҫ��������Ԫ�صĵ�ַ�Լ���ַ��ռ�õ��ڴ��С����λ���ֽ�
////һ���ֽ�һ���ֽڵĽ��н���
//void swap(char* p1, char* p2, int width)
//{
//	int j = 0;
//	for (j = 0; j < width; j++)//һ���ֽ�һ���ֽڵĽ��н���
//	{
//		char temp = *p1;//����һ���������
//		*p1 = *p2;
//		*p2 = temp;//���н���
//		p1++;
//		p2++;//������һ���ֽ�
//	}
//}
//
////�ȽϺ�����ʵ�֣�����Ա֪���Լ���Ҫ�Ƚϵ���ʲô����
////Ȼ����д�������
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
////ð����������ʵ��
//void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	//����sz-1��ð������
//	for (i = 0; i < sz-1; i++)
//	{
//		int ii = 0;
//		//ÿһ��ð��������Ҫ��Ԫ�ؽ���sz-i-1�αȽ�����
//		for (ii = 0; ii < sz - i - 1; ii++)
//		{
//			//cmp�ǱȽϺ�������Ҫ�Լ�ʵ�֣���cmp�ķ���ֵ>0ʱ��˵����һ��Ԫ�رȽϴ�
//			if (cmp((char*)base + ii * width, (char*)base + (ii + 1) * width) > 0)
//				//���ȷ���˵�һ��Ԫ�رȽϴ��򽻻�����Ԫ�ص�λ��
//				swap((char*)base + ii * width, (char*)base + (ii + 1) * width, width);
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };//���鶨��
//	int sz = sizeof(arr) / sizeof(int);//��������Ĵ�С
//	bubble_sort(arr, sz, sizeof(int), cmp_int);//qsort��ģ��ʵ��
//	for (int index = 0; index < sz; index++)//��ӡ����֮�������arr
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

//ð�ݺ���
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
//		printf("��ѡ����������ܣ�->\n");
//		scanf("%d", &input);
//		if (input > 0 && input < sizeof(parr))
//		{
//			printf("������������������->\n");
//			scanf("%d%d", &a, &b);
//			printf("%d\n", parr[input](a, b));
//		}
//		else if (0 == input)
//		{
//			printf("�˳�\n");
//		}
//		else
//		{
//			printf("����������������룺\n");
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
//	int arr[10] = { 0 };//��������
//	char ch[5] = { 0 };//�ַ�����
//	int* parr[10] = { NULL };//���������intָ�������-ָ������
//	char* pch[5] = { NULL };//���������charָ�������-ָ������
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
//	//����һ�������ַ���
//	//p�洢�����ַ������׵�ַ
//	printf("%c\n", *p);
//	printf("%s\n", p);
//
//	return 0;
//}

//int main()
//{
//	char* p = "abcdef";
//	//����һ�������ַ���
//	//p�洢�����ַ������׵�ַ
//	printf("%c\n", *p);
//	printf("%s\n", p);
//
//	return 0;
//}


