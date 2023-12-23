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

//获取Hash值；
int Hash(int key, int TableSize);

//初始化哈希表；
HashTable* InitHash(int TableSize);

//Hash Table查找元素
Element HashFind(HashTable* HashTable, int key);

//提取哈希表中的元素的值
void* Retrieve(Element e);

//哈希表插入元素，元素为键值对
void HashInsert(HashTable* HashTable, int key, void* value);

//Hash表删除元素；元素为键值对；
void HashDelete(HashTable* HashTable, int key);

//摧毁Hash表
void HashDestory(HashTable* HashTable);
