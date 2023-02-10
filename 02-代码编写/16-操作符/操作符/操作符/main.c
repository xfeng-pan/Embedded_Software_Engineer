#include <stdio.h>

struct Stu
{
	char name[20];
	int age;
	char id[20];
};

int main()
{
	int a = 10;
	struct Stu s1 = { "zhangsan",20,"20212230" };
	s1.age = a;
	struct Stu* ps = &s1;
	printf("%s\n", s1.name);
	printf("%d\n", s1.age);
	printf("%s\n", s1.id);

	printf("%s\n", (*ps).name);
	printf("%d\n", (*ps).age);
	printf("%s\n", (*ps).id);

	printf("%s\n", ps->name);
	printf("%d\n", ps->age);
	printf("%s\n", ps->id);

	return 0;
}


//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = (a > b, a = b + 10, a, b = a + 1);
//	printf("%d\n", c);
//	return 0;
//}



//int main()
//{
//	int a = 1;
//	int b = 2;
//	printf("%d\n", (a > b) ? a : b);
//	return 0;
//}


//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	//a=1;
//	i = a++ && ++b && d++;
//	//i= a++ || ++b || d++;
//	printf("%d %d %d %d\n", a, b, c, d);
//	return 0;
//	//程序的输出结果是什么？
//}

//int main()
//{
//	int a = 11;
//	a = a | (1 << 2);
//	//位操作的使用技巧，将1011变成1111
//	printf("%d\n", a);
//
//	a = a & (~(1 << 2));
//	printf("%d\n", a);
//	//再将1111变成1011
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	printf("%d\n", ~a);
//	return 0;
//}

//int main()
//{
//	short s = 0;
//	int a = 10;
//	printf("%d\n", sizeof(s = a + 5));
//	printf("%d\n", s);
//	return 0;
//}


//
//int main()
//{
//	int a = 5;
//	int b = 3;
//
//	printf("Before:a=%d,b=%d\n", a, b);
//	//加减法，可能会溢出
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("After:a=%d,b=%d\n", a, b);
//	//异或：
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//
//	printf("Last:a=%d,b=%d\n", a, b);
//		return 0;
//}


//int main()
//{
//	int a = 1;
//	//0001
//	int b = 2;
//	//0010
//	int c = a & b;
//	//0000
//	int d = a | b;
//	//0011
//	int e = a ^ b;
//	//0011
//	printf("%d\n", c);
//	printf("%d\n", d);
//	printf("%d\n", e);
//	return 0;
//}


//int main()
//{
//	int a = -8;
//	int b = -1;
//	a >> 1;
//	int c = b << 1;
//	printf("%d\n", a >> 1);
//	printf("%d\n", b);
//	printf("%d\n", c);
//
//	return 0;
//}