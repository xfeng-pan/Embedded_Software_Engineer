#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

struct Book
{
	char name[40];
	float price;
};

int main()
{
	struct Book b1 = { "C���Գ������",12.99 };
	struct Book* pb = &b1;//�ṹ��ָ��

	strcpy(pb->name, "C++�������");
	printf("��������%s\n", (*pb).name);
	return 0;
}
	//printf("-------------------------\n");
	//printf("���ýṹ���ӡ���޸���Ϣ\n");
	//printf("������%s\n", b1.name);
	//printf("�۸�%.2f\n", b1.price);
	//printf("�����ۺ�ļ۸�Ϊ��%.2f\n", b1.price * 0.85);
	//printf("-------------------------\n");
	//printf("����ָ���ӡ���޸���Ϣ\n");
	//printf("������%s\n", (*pb).name);
	//printf("�۸�%.2f\n", (*pb).price);
	//printf("�����ۺ�ļ۸�Ϊ��%.2f\n", (*pb).price * 0.85);
	//printf("-------------------------\n");
	//printf("����ָ��->��ӡ���޸���Ϣ\n");
	//printf("������%s\n", pb->name);
	//printf("�۸�%.2f\n", pb->price);
	//printf("�����ۺ�ļ۸�Ϊ��%.2f\n", pb->price * 0.85);
//	return 0;
//}