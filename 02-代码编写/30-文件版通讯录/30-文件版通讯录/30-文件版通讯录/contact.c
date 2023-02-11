#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//初始化通讯录
void InitContact(struct Contact* ps)
{
	ps->data = NULL;
	//ps->data=(struct PeoInfo*) malloc(3 * sizeof(struct PeoInfo));//这样开辟的空间里面是随机值
	ps->data=(struct PeoInfo*) calloc(DEFAULT_SZ, sizeof(struct PeoInfo));//开辟空间的同时，清零
	if (ps->data == NULL)
	{
		printf("通讯录内存开辟失败\n");
		printf("%s\n", strerror(errno));
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	//把文件中已经有的信息加载到通讯录中
	LoadContact(ps);

}

//检测容量
void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		struct PeoInfo* ptr= realloc(ps->data,(ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("扩容成功\n");
		}
		else
		{
			printf("扩容失败\n");
		}
	}
}

//增加一个元素到通讯录中
void AddContact(struct Contact* ps)
{
	//首先判断通讯录是不是满了
	//1.如果满了，就扩容
	//2.如果不满，就什么都不做
	CheckCapacity(ps);

	//增加数据
		printf("请输入名字->");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄->");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别->");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话->");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址->");
		scanf("%s", ps->data[ps->size].addres);

		ps->size++;
		printf("添加成功\n");


	// 
	////首先判断通讯录是不是满了
	//if (ps->size == MAX)
	//{
	//	printf("通讯录已满，无法增加\n");
	//}
	//else
	//{
	//	printf("请输入名字->");
	//	scanf("%s", ps->data[ps->size].name);
	//	printf("请输入年龄->");
	//	scanf("%d", &(ps->data[ps->size].age));
	//	printf("请输入性别->");
	//	scanf("%s", ps->data[ps->size].sex);
	//	printf("请输入电话->");
	//	scanf("%s", ps->data[ps->size].tele);
	//	printf("请输入地址->");
	//	scanf("%s", ps->data[ps->size].addres);

	//	ps->size++;
	//	printf("添加成功\n");

	//}
}

//显示通讯录
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		//标题
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		//数据
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

//修饰这个函数
//普通函数具有外部链接属性，被static修饰后，变成了内部链接属性
//找得到返回位置
//找不到返回-1
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


//删除通讯录中的指定联系人
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除的人的名字");
	scanf("%s", name);

	//1. 查找要删除的人在什么位置
	int pos = FindByName(ps, name);


	//2. 删除
	if (pos == ps->size)
	{
		printf("查无此人\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;//减小通讯录的大小
		printf("已成功删除成员：%s\n", name);
	}
}



//查找指定人的信息
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找的人的名字");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addres);
	}
}

//修改指定人的信息
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改的人的名字");
	scanf("%s", name);
	//1.查找
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	//2.修改
	else
	{
		printf("请输入名字->");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄->");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别->");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话->");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址->");
		scanf("%s", ps->data[pos].addres);

		printf("修改成员：%s\n", ps->data[pos].name);
	}
	
}

//释放动态开辟的内存
void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

//保存文件
void SaveContace(struct Contact* ps)
{
	//打开文件
	FILE* pfWrite = fopen("contat.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	//写文件
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfWrite);
	}

	//关文件
	fclose(pfWrite);
	pfWrite = NULL;

	printf("保存成功!\n");

}

//加载文件中的信息到通讯录
void LoadContact(struct Contact* ps)
{
	PeoInfo tmp = { 0 };
	//打开文件
	FILE* PfRead = fopen("contat.dat", "rb");
	if (PfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	//读取文件
	while (fread(&tmp, sizeof(PeoInfo), 1, PfRead))//fread会返回实际读到的元素的个数
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}

	//关闭文件
	fclose(PfRead);
	PfRead = NULL;
}