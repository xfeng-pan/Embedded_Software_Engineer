#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stddef.h>


union un
{
	int a;
	//自身大小：4
	//默认对齐数：8
	//最终对齐数：4
	char arr[5];
	//数组的对齐数计算：
	//使用数组元素的大小来计算
	//数组元素的大小：1
	//默认对齐数：8
	//最终对齐数：1
};

int main()
{
	union un u;
	printf("%d\n", sizeof(u));
	return 0;
}




////无输入参数
////返回1：系统是小端存储
////返回0：系统是大端存储
//
//int check_sys()
//{
//	union SYS
//	{
//		char c;
//		int i;
//	}sys;
//	sys.i = 1;
//	return sys.c;
//}
//
//int main()
//{
//	printf("%d\n", check_sys());
//	return 0;
//}



////无输入参数
////返回1：系统是小端存储
////返回0：系统是大端存储
//int check_sys()
//{
//	int sys = 1;
//	return *((char*)&sys);
//}
//
//int main()
//{
//	printf("%d\n", check_sys());
//}


//int main()
//{
//	int a = 0x01;
//	int* p = &a;
//	
//	//强制类型转换
//	//只读取一个字节
//	if ('\0' == *((char*)p))
//	{
//		printf("大端存储\n");
//	}
//	else if ('\1' == *((char*)p))
//	{
//		printf("小端存储\n");
//	}
//	else
//		printf("err\n");
//	return 0;
//}


//union Un
//{
//	char c;
//	int i;
//};
//
//int main()
//{
//	union Un u;
//	u.i = 0x11223344;
//	u.c = 0x55;
//	printf("%x\n", u.c);//0x55
//	printf("%x\n", u.i);//0x11223355
//}



////联合类型的声明
//union Un
//{
//	char c;
//	int i;
//};
//
//int main()
//{
//	//联合变量的定义
//	union Un u;
//	//计算连个变量的大小
//	printf("%d\n", sizeof(u));
//
//	//打印联合体在内存中的地址
//	printf("%p\n", &u);
//	printf("%p\n", &(u.c));
//	printf("%p\n", &(u.i));//三个地址都一样
//	return 0;
//}

//enum Sex
//{
//	MALE,
//	FEMALE,
//	SECRET
//};
//
//int main()
//{
//	enum Sex s = MALE;
//	printf("%d\n", sizeof(enum Sex));
//	printf("%d\n", sizeof(s));
//	return 0;
//}


////枚举类型
//enum Sex
//{
//	//枚举常量
//	MALE,
//	FEMALE,
//	SECRET
//};
//
//enum Color
//{
//	RED=2,
//	GREEN,
//	BLUE=8
//};
//
//int main()
//{
//	enum Sex s = MALE;
//	enum Color c = GREEN;
//	printf("%d %d \n", s, c);
//	printf("%d %d %d \n", MALE,FEMALE,SECRET);
//	printf("%d %d %d \n", RED,GREEN,BLUE);
//
//	return 0;
//}



//struct s
//{
//	char c;
//	int a;
//	double d;
//};
//
////用传址进行初始化
//void Init(struct s* ps)
//{
//	ps->c = 'w';
//	ps->a = 1;
//	ps->d = 3.14159;
//}
//
////用传值进行打印，缺点是会额外占用空间
//void Print1(struct s tem)
//{
//	printf("%c ", tem.c);
//	printf("%d ", tem.a);
//	printf("%.2f", tem.d);
//	printf("\n");
//}
//
////用传址进行打印，并利用const进行修饰，避免内部值被修改
//void Print2( const struct s* ps)
//{
//	printf("%c ", ps->c);
//	printf("%d ", ps->a);
//	printf("%.2f ", ps->d);
//	printf("\n");
//}
//
//int main()
//{
//	struct s s1 = { 0 };
//	Init(&s1);
//	Print1(s1);
//	Print2(&s1);
//	return 0;
//}



//struct s
//{
//	char c;
//	int a;
//	double d;
//};
//
//int main()
//{
//	printf("%d\n", offsetof(struct s, c));
//	printf("%d\n", offsetof(struct s, a));
//	printf("%d\n", offsetof(struct s, d));
//	return 0;
//}


//struct s1
//{
//	char c;
//	double d;
//};
//
//#pragma pack(4)
//struct s2
//{
//	char c;
//	double d;
//};
//#pragma pack()
//
//int main()
//{
//	struct s1 s1 = { 0 };
//	struct s2 s2 = { 0 };
//	printf("%d\n", sizeof(s1));
//	printf("%d\n", sizeof(s2));
//	return 0;
//}




//struct s1
//{
//	char c1;
//	int a1;
//	char c2;
//};
//
//struct s2
//{
//	char c3;
//	char c4;
//	int a2;
//};
//
//struct s3
//{
//	double d;
//	char c;
//	int i;
//};
//
//struct s4
//{
//	char c;
//	struct s3 s3;
//	double d;
//};
//
//
//
//int main()
//{
//	struct s1 s1 = { 0 };
//	struct s2 s2 = { 0 };
//	struct s3 s3 = { 0 };
//	struct s4 s4 = { 0 };
//	printf("%d\n", sizeof(s1));
//	printf("%d\n", sizeof(s2));
//	printf("%d\n", sizeof(s3));
//	printf("%d\n", sizeof(s4));
//	return 0;
//}

////结构体的嵌套初始化
//
//struct time
//{
//	int year;
//	int month;
//	int date;
//};
//
//typedef struct chatlog
//{
//	struct time t;
//	char sentence1[20];
//	char sentence2[20];
//	char sentence3[20];
//}chatlog;
//
//int main()
//{
//	chatlog log = { {2023,02,02},"hello","world","!!!" };
//	printf("%d %d %d : %s %s %s\n", log.t.year, log.t.month, log.t.date, 
//		log.sentence1, log.sentence2, log.sentence3);
//	return 0;
//}



////typedef复习
//typedef struct Node//声明一个叫做Node类型的结构体变量
//{
//	int a;
//	struct Node* next;
//}Node;//将struct Node通过typedef简化为Node，方便后续使用
//
//int main()
//{
//	struct Node n1;//完整的声明创建n1结构体变量
//	Node n2;//通过typedef进行的简化声明创建n2结构体变量
//
//	return 0;
//}

//struct node
//{
//    //数据域，用于存储数据，可以是int，char，或者其他类型的数据
//    int a;
//    //指针域，用于存储下一个链表节点的地址
//    struct node* next;
//};




////匿名结构体：
//
//struct
//{
//	int a;
//	char c;
//}sa;
//
//struct
//{
//	int a;
//	char c;
//}*psa;
//
//int main()
//{
//	psa = &sa;
//	return 0;
//}


//声明一个结构体类型
//声明一个学生类型，通过以学生类型来创建学生变量
//描述学生：属性-姓名+电话+性别+年龄
//
//struct stu1
//{
//	char name[20];
//	char tel[12];
//	char sex[10];
//	int age;
//};//这里只声明了类型，并没有创建变量
//
//struct stu2
//{
//	char name[20];
//	char tel[12];
//	char sex[10];
//	int age;
//}s1,s2;//这里不但声明了类型，还创建了s1,s2两个变量
//
//利用typedef关键字可以简化结构体的定义过程
//
//typedef struct stu3//也可省略stu3
//{
//	成员变量
//	char name[20];
//	int age;
//	char tele[12];
//	char sex[6];
//}STU;//通过typedef将struct Stu3重命名为STU
//
//
//int main()
//{
//	利用typedef关键字重命名的STU来创建变量名
//	STU s3 = { "example",18,"12345678910","female" };
//	return 0;
//}















