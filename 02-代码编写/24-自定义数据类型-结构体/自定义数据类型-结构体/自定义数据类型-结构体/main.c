#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stddef.h>

union un
{
	int a;
	//�����С��4
	//Ĭ�϶�������8
	//���ն�������4
	char arr[5];
	//����Ķ��������㣺
	//ʹ������Ԫ�صĴ�С������
	//����Ԫ�صĴ�С��1
	//Ĭ�϶�������8
	//���ն�������1
};

int main()
{
	union un u;
	printf("%d\n", sizeof(u));
	return 0;
}




////���������
////����1��ϵͳ��С�˴洢
////����0��ϵͳ�Ǵ�˴洢
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



////���������
////����1��ϵͳ��С�˴洢
////����0��ϵͳ�Ǵ�˴洢
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
//	//ǿ������ת��
//	//ֻ��ȡһ���ֽ�
//	if ('\0' == *((char*)p))
//	{
//		printf("��˴洢\n");
//	}
//	else if ('\1' == *((char*)p))
//	{
//		printf("С�˴洢\n");
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



////�������͵�����
//union Un
//{
//	char c;
//	int i;
//};
//
//int main()
//{
//	//���ϱ����Ķ���
//	union Un u;
//	//�������������Ĵ�С
//	printf("%d\n", sizeof(u));
//
//	//��ӡ���������ڴ��еĵ�ַ
//	printf("%p\n", &u);
//	printf("%p\n", &(u.c));
//	printf("%p\n", &(u.i));//������ַ��һ��
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


////ö������
//enum Sex
//{
//	//ö�ٳ���
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
////�ô�ַ���г�ʼ��
//void Init(struct s* ps)
//{
//	ps->c = 'w';
//	ps->a = 1;
//	ps->d = 3.14159;
//}
//
////�ô�ֵ���д�ӡ��ȱ���ǻ����ռ�ÿռ�
//void Print1(struct s tem)
//{
//	printf("%c ", tem.c);
//	printf("%d ", tem.a);
//	printf("%.2f", tem.d);
//	printf("\n");
//}
//
////�ô�ַ���д�ӡ��������const�������Σ������ڲ�ֵ���޸�
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

////�ṹ���Ƕ�׳�ʼ��
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



////typedef��ϰ
//typedef struct Node//����һ������Node���͵Ľṹ�����
//{
//	int a;
//	struct Node* next;
//}Node;//��struct Nodeͨ��typedef��ΪNode���������ʹ��
//
//int main()
//{
//	struct Node n1;//��������������n1�ṹ�����
//	Node n2;//ͨ��typedef���еļ���������n2�ṹ�����
//
//	return 0;
//}

//struct node
//{
//    //���������ڴ洢���ݣ�������int��char�������������͵�����
//    int a;
//    //ָ�������ڴ洢��һ������ڵ�ĵ�ַ
//    struct node* next;
//};




////�����ṹ�壺
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


//����һ���ṹ������
//����һ��ѧ�����ͣ�ͨ����ѧ������������ѧ������
//����ѧ��������-����+�绰+�Ա�+����
//
//struct stu1
//{
//	char name[20];
//	char tel[12];
//	char sex[10];
//	int age;
//};//����ֻ���������ͣ���û�д�������
//
//struct stu2
//{
//	char name[20];
//	char tel[12];
//	char sex[10];
//	int age;
//}s1,s2;//���ﲻ�����������ͣ���������s1,s2��������
//
//����typedef�ؼ��ֿ��Լ򻯽ṹ��Ķ������
//
//typedef struct stu3//Ҳ��ʡ��stu3
//{
//	��Ա����
//	char name[20];
//	int age;
//	char tele[12];
//	char sex[6];
//}STU;//ͨ��typedef��struct Stu3������ΪSTU
//
//
//int main()
//{
//	����typedef�ؼ�����������STU������������
//	STU s3 = { "example",18,"12345678910","female" };
//	return 0;
//}















