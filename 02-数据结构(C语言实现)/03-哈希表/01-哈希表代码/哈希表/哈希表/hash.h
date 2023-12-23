#pragma once

#define DEFAULT_SIZE 16


typedef struct ListNode
{
	struct ListNode* next;
	int key;
	void* data;
}ListNode;

typedef ListNode* List;
typedef ListNode* Element;

typedef struct HashTable
{
	int TableSize;
	List* TheLists;
}HashTable;

//��ȡHashֵ��
int Hash(int key, int TableSize);

//��ʼ����ϣ��
HashTable* InitHash(int TableSize);

//Hash Table����Ԫ��
Element HashFind(HashTable* HashTable, int key);

//��ȡ��ϣ���е�Ԫ�ص�ֵ
void* Retrieve(Element e);

//��ϣ�����Ԫ�أ�Ԫ��Ϊ��ֵ��
void HashInsert(HashTable* HashTable, int key, void* value);

//Hash��ɾ��Ԫ�أ�Ԫ��Ϊ��ֵ�ԣ�
void HashDelete(HashTable* HashTable, int key);

//�ݻ�Hash��
void HashDestory(HashTable* HashTable);
