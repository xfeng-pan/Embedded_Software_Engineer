#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
	//打开文件
	FILE* pf = fopen("test.txt", "r");
	if (!pf)
	{
		//perror：报错的时候会显示信息与自定义内容
		perror("fopen:");//一种报错方式
		return 0;
	}

	//读文件
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		//五种文件输出格式，理论上输出六个字符
		putc(ch,stdout);
		putchar(putc(ch, stdout));//putc，putchar的返回值是输出的字符
		fputc(ch, stdout);
		printf("%c",ch);
		fprintf(stdout, "%c\n", ch);
	}
	if (ferror(pf)) printf("error\n");
	else if (feof(pf)) printf("end of file\n");

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;

}

//int main()
//{
//	//EOF
//	//feof();//end of file:文件结束标志
//	//其值是-1
//
//	FILE* pf = fopen("test2.txt", "r");
//	if (!pf)
//	{
//		perror("fopen:");//一种新的报错方式
//		return 0;
//	}
//
//	int ch = fgetc(pf);
//
//	printf("%d", ch);//如果输出-1，则代表文件结束了
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	printf("%ld\n", ftell(pf));
//	//定位文件指针
//	fseek(pf, 2, SEEK_CUR);//偏移到C
//	//读取文件
//	char ch = fgetc(pf);
//	putc(ch,stdout);
//
//	//定位文件指针
//	fseek(pf, 2, SEEK_CUR);//偏移到F
//	//读取文件
//	ch = fgetc(pf);//读完F之后，自动偏移到G
//	putc(ch, stdout);
//
//	//定位文件指针
//	fseek(pf, -2, SEEK_CUR);//偏移-2，偏移到E
//	//读取文件
//	ch = fgetc(pf);//读取完成之后自动偏移到F（F的偏移量是5）
//	putc(ch, stdout);
//
//	printf("\n%ld\n", ftell(pf));
//
//	rewind(pf);//定位到文件开头
//
//	printf("%ld\n", ftell(pf));
//	//读取文件
//	ch = fgetc(pf);//读取完成之后自动偏移到F（F的偏移量是5）
//	putc(ch, stdout);
//
//	//关闭文件
//	fclose(pf);
//	return 0;
//}

//typedef struct S
//{
//	char namr[20];
//	int age;
//	double score;
//}S;
//
//int main()
//{
//	S tmp = { 0 };
//
//	//打开文件
//	FILE* pf = fopen("test.txt", "rb");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//二进制形式写文件
//	fread(&tmp, sizeof(S), 1, pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	S s = { "xyz",18,100.0 };
//
//	//打开文件
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//二进制形式写文件
//	fwrite(&s, sizeof(S), 1, pf);
//	
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//typedef struct S
//{
//	int n;
//	float f;
//	char arr[20];
//}ss;
//
//int main()
//{
//	ss s = { 100,3.14f,"abcdef" };
//	ss tmp = { 0 };
//	char buf[1024] = { 0 };
//
//	sprintf(buf,"%d %.2f %s", s.n, s.f, s.arr);
//	printf("%s\n", buf);
//	sscanf(buf,"%d %f %s", &(tmp.n), &(tmp.f), tmp.arr);
//	printf("%d %.2f %s", tmp.n, tmp.f, tmp.arr);
//	return 0;
//}

//int main()
//{
//	s s1 = { 0 };
//	fscanf(stdin, "%d %f %s", &(s1.n), &(s1.f), s1.arr);
//	fprintf(stdout, "%d %.2f %s", s1.n, s1.f, s1.arr);
//	return 0;
//}

//int main()
//{
//	s s = { 0 };
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//读取文件
//	fscanf(pf,"%d %f %s",&(s.n),&(s.f),s.arr);
//	//scanf("%d %f %s", &(s.n), &(s.f), s.arr);
//	printf("%d %.2f %-20s", s.n, s.f, s.arr);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	s s1 = { 3,3.14f,"hello" };//有f后缀是float，没有f后缀默认是double型
//	//打开文件
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//写文件
//	fprintf(pf, "%d %.2f %-20s", s1.n, s1.f, s1.arr);//格式化输出文件
//	printf("%d %.2f %-20s", s1.n, s1.f, s1.arr);//fprintf与printf的区别其实并不大
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	char buf[1024] = { 0 };
//	gets(buf);
//	puts(buf);
//
//	return 0;
//}

//int main()
//{
//	char buf[1024] = { 0 };
//
//	fgets(buf, 1024, stdin);
//	fputs(buf, stdout);
//
//	return 0;
//}

//int main()
//{
//	char buf[1024] = { 0 };
//	//打开文件
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 0;
//	}
//	//写文件
//	fputs("Hello\n", pf);
//	fputs("Word!!", pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//}

//int main()
//{
//	char buf[1024] = { 0 };
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 0;
//	}
//	//读取文件
//	fgets(buf, 1024, pf);
//	puts(buf);//将流文件输出到标准输入输出流中 puts会自动增加换行
//	fgets(buf, 1024, pf);
//	puts(buf);//将流文件输出到标准输入输出流中 puts会自动增加换行
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	char buf[1024] = { 0 };
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 0;
//	}
//	//读取文件
//	fgets(buf,1024,pf);
//	printf("%s",buf);//文件本身有一个换行
//	fgets(buf, 1024, pf);
//	printf("%s",buf);//
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//}

//int main()
//{
//	//打开文件
//	//FILE* pf = fopen("test2.txt", "w");//写
//	FILE* pf = fopen("test2.txt", "r");//读
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 0;
//	}
//	//写文件
//	//fputc('x', pf);
//	//fputc('y', pf);
//	//fputc('z', pf);
//
//	//读文件
//	printf("%c ",fgetc(pf));
//	printf("%c ",fgetc(pf));
//	printf("%c ",fgetc(pf));
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//
//}

//int main()
//{
//	//标准输入流
//	int ch = fgetc(stdin);
//	//标准输出流
//	fputc(ch, stdout);
//
//	return 0;
//}

//int main()
//{
//	//打开文件
//	FILE* pfread = fopen("TEST1.txt", "r");
//	if (pfread == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//读文件
//	printf("%c ", fgetc(pfread));
//	printf("%c ", fgetc(pfread));
//	printf("%c ", fgetc(pfread));
//	//关闭文件
//	fclose(pfread);
//	pfread = NULL;
//	return 0;
//}

//int main()
//{
//	//打开文件
//	FILE* pfwrite = fopen("TEST1.txt", "w");
//	if (pfwrite == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//写文件
//	fputc('x', pfwrite);
//	fputc('y', pfwrite);
//	fputc('z', pfwrite);
//	//关闭文件
//	fclose(pfwrite);
//	pfwrite = NULL;
//	return 0;
//}

//int main()
//{
//	//打开文件test.txt
//	// 相对路径
//	// . 表示当前路径
//	// .. 表示上一级路径
//	// ../.. 表示上上级路径
//	//fopen("../test1.txt", "r");
//	
//
//	//绝对路径
//	//fopen("F:\\05-能力提升\\16-C语言提升\\02-代码编写\\29-文件操作\\29-文件操作\\test.txt", "r");
//
//	FILE* pf = fopen("test.txt", "r");
//
//	if (pf == NULL)
//	{
//		//打开失败
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		printf("打开成功\n");
//	}
//	//打开成功
//	//读文件
//	//关闭文件
//	fclose(pf);
//	pf = NULL;;
//
//	return 0;
//}


//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");//w：写   b：以二进制的形式来写
//	fwrite(&a, 4, 1, pf);//以二进制的形式写入文件中
//	//表示数据来自a，
//	//写的数据的类型是4个字节的;
//	//写一个这种类型的数据;
//	//写到pf指针所指的地方
//
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


