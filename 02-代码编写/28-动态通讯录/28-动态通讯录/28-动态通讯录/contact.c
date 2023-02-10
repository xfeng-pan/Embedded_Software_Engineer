#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps)
{
	ps->data = NULL;
	//ps->data=(struct PeoInfo*) malloc(3 * sizeof(struct PeoInfo));//�������ٵĿռ����������ֵ
	ps->data=(struct PeoInfo*) calloc(DEFAULT_SZ, sizeof(struct PeoInfo));//���ٿռ��ͬʱ������
	if (ps->data == NULL)
	{
		printf("ͨѶ¼�ڴ濪��ʧ��\n");
		printf("%s\n", strerror(errno));
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;

}

//�������
void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		struct PeoInfo* ptr= realloc(ps->data,(ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}
	}
}

//����һ��Ԫ�ص�ͨѶ¼��
void AddContact(struct Contact* ps)
{
	//�����ж�ͨѶ¼�ǲ�������
	//1.������ˣ�������
	//2.�����������ʲô������
	CheckCapacity(ps);

	//��������
		printf("����������->");
		scanf("%s", ps->data[ps->size].name);
		printf("����������->");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�->");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰->");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ->");
		scanf("%s", ps->data[ps->size].addres);

		ps->size++;
		printf("��ӳɹ�\n");


	// 
	////�����ж�ͨѶ¼�ǲ�������
	//if (ps->size == MAX)
	//{
	//	printf("ͨѶ¼�������޷�����\n");
	//}
	//else
	//{
	//	printf("����������->");
	//	scanf("%s", ps->data[ps->size].name);
	//	printf("����������->");
	//	scanf("%d", &(ps->data[ps->size].age));
	//	printf("�������Ա�->");
	//	scanf("%s", ps->data[ps->size].sex);
	//	printf("������绰->");
	//	scanf("%s", ps->data[ps->size].tele);
	//	printf("�������ַ->");
	//	scanf("%s", ps->data[ps->size].addres);

	//	ps->size++;
	//	printf("��ӳɹ�\n");

	//}
}

//��ʾͨѶ¼
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		//����
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		//����
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addres
			);
		}
	}
}

//�����������
//��ͨ���������ⲿ�������ԣ���static���κ󣬱�����ڲ���������
//�ҵõ�����λ��
//�Ҳ�������-1
static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}


//ɾ��ͨѶ¼�е�ָ����ϵ��
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ�����˵�����");
	scanf("%s", name);

	//1. ����Ҫɾ��������ʲôλ��
	int pos = FindByName(ps, name);


	//2. ɾ��
	if (pos == ps->size)
	{
		printf("���޴���\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;//��СͨѶ¼�Ĵ�С
		printf("�ѳɹ�ɾ����Ա��%s\n", name);
	}
}



//����ָ���˵���Ϣ
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ��˵�����");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addres);
	}
}

//�޸�ָ���˵���Ϣ
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ��˵�����");
	scanf("%s", name);
	//1.����
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	//2.�޸�
	else
	{
		printf("����������->");
		scanf("%s", ps->data[pos].name);
		printf("����������->");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�->");
		scanf("%s", ps->data[pos].sex);
		printf("������绰->");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ->");
		scanf("%s", ps->data[pos].addres);

		printf("�޸ĳ�Ա��%s\n", ps->data[pos].name);
	}
	
}


