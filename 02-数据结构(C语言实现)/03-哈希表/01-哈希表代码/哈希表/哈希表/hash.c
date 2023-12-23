#define _CRT_SECURE_NO_WARNINGS 1

#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//��ȡHashֵ��
int Hash(int key, int TableSize)
{
	return key % TableSize;
}

//��ʼ����ϣ��
HashTable* InitHash(int TableSize)
{
	int i = 0;
	HashTable* hTable = NULL;

	if (TableSize <= 0)
	{
		TableSize = DEFAULT_SIZE;
	}

	hTable = (HashTable*)malloc(sizeof(HashTable));

	if (hTable == NULL)
	{
		printf("malloc hTable failed!\r\n");
		return NULL;
	}
	hTable->TableSize = TableSize;

	//Ϊ��ϣͰ�����ڴ�ռ䣬��Ϊһ��ָ�����飻
	hTable->TheLists = (List*)malloc(sizeof(List) * TableSize);
	if (hTable->TheLists == NULL)
	{
		printf("TheLists malloc failed!\r\n");
		return NULL;
	}

	//ΪHashͰ��Ӧ��ָ�������ʼ������ڵ㣻
	for (i = 0; i < TableSize; i++)
	{
		hTable->TheLists[i] = (ListNode*)malloc(sizeof(ListNode));
		if (hTable->TheLists[i] == NULL)
		{
			printf("ListNode malloc failed!\r\n");
			for (int j = 0; j < i; j++)
			{
				free(hTable->TheLists[j]);
			}
			free(hTable->TheLists);
			free(hTable);
			return NULL;
		}
		else
		{
			memset(hTable->TheLists[i], 0, sizeof(ListNode));
		}
	}
	return hTable;
}

//Hash Table����Ԫ��
Element HashFind(HashTable* HashTable, int key)
{
	assert(HashTable);
	int i = 0;//���ڴ洢hashֵ��
	List L = NULL;
	Element e= NULL;

	i = Hash(key, HashTable->TableSize);
	L = HashTable->TheLists[i];
	e = L->next;

	while (e != NULL && e->key != key)
	{
		e = e->next;
	}
	if (e == NULL)
	{
		printf("Not Find, key: %d \r\n", i);
		return NULL;
	}
	return e;
}

//��ȡ��ϣ���е�Ԫ�ص�ֵ
void* Retrieve(Element e)
{
	return e? e->data:NULL;
}

//��ϣ�����Ԫ�أ�Ԫ��Ϊ��ֵ��
void HashInsert(HashTable* HashTable, int key, void* value)
{
	assert(HashTable);
	Element e = NULL, tmp = NULL;
	List L = NULL;
	
	e = HashFind(HashTable, key);

	if (e == NULL)
	{
		tmp = (Element)malloc(sizeof(ListNode));
		if (NULL == tmp)
		{
			printf("Element malloc failed!\r\n");
			exit(-1);
		}
		L = HashTable->TheLists[Hash(key, HashTable->TableSize)];

		tmp->data = value;
		tmp->key = key;
		tmp->next = L->next;//ǰ�巨

		L->next = tmp;
	}
	else
	{
		printf("the key already exist!\r\n");
	}
}

//Hash��ɾ��Ԫ�أ�Ԫ��Ϊ��ֵ�ԣ�
void HashDelete(HashTable* HashTable, int key)
{
	int i = Hash(key, HashTable->TableSize);
	Element Last = HashTable->TheLists[i];
	Element tmp = Last->next;

	while (tmp != NULL && tmp->key != key)
	{
		Last = tmp;
		tmp = tmp->next;
	}
	if (tmp != NULL)
	{
		Last->next = tmp->next;
		free(tmp);
	}
}


//�ݻ�Hash��
void HashDestory(HashTable* HashTable)
{
	assert(HashTable);
	List L = NULL;
	Element cur = NULL, next = NULL;

	for (int i = 0; i < HashTable->TableSize; i++)
	{
		L = HashTable->TheLists[i];
		cur = L->next;
		while (cur != NULL)
		{
			next = cur->next;
			free(cur);
			cur = next;
		}
		free(L);
	}
	free(HashTable->TheLists);
	free(HashTable);

	printf("HashDestory sucess!\r\n");

}