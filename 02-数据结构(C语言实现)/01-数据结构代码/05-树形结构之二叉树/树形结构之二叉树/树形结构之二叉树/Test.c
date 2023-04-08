#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
	//ǰ�����
}
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
	//�������

}
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
	//�������

}

//������Ĵ�С
//����һ������
//���Զ���ȫ�ֱ��������߶���static����  ���������ٴε���֮ǰ����Ҫ������λ0����˴�ַ������
//������������˼��
void TreeSize(BTNode* root, int* psize)
{
	if (root == NULL)
	{
		return;
	}
	(*psize)++;
	TreeSize(root->left, psize);
	TreeSize(root->right, psize);
}
//������������˼��
int TreeSizeF(BTNode* root)
{
	return root == NULL ? 0 : TreeSizeF(root->left) + TreeSizeF(root->right) + 1;
}

//���÷���˼����Ҷ�ӽڵ�ĸ���
int Treeleafsize(BTNode* root)
{
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return 1;
	else
	{
		return Treeleafsize(root->left) + Treeleafsize(root->right);
	}
}
//�������Ĳ������
void LeveOrder(BTNode* root)
{
	assert(root);
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!IsQueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\r\n");
	QueueDestory(&q);
}


void TreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	TreeDestory(root->left);
	TreeDestory(root->right);
	printf("Destory: %c \r\n", root->data);
	free(root);
}


int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	PreOrder(A);
	printf("\r\n");
	InOrder(A);
	printf("\r\n");
	PostOrder(A);
	printf("\r\n");

	int SizeA = 0;
	int SizeB = 0;
	int SizeC = 0;
	TreeSize(A, &SizeA);
	TreeSize(B, &SizeB);
	TreeSize(C, &SizeC);
	printf("TreeSizeA: %d \r\n", SizeA);
	printf("TreeSizeB: %d \r\n", SizeB);
	printf("TreeSizeC: %d \r\n", SizeC);

	printf("TreeSizeA: %d \r\n", TreeSizeF(A));
	printf("TreeSizeB: %d \r\n", TreeSizeF(B));
	printf("TreeSizeC: %d \r\n", TreeSizeF(C));


	printf("TreeleafSize: %d \r\n", Treeleafsize(A));
	printf("TreeleafSize: %d \r\n", Treeleafsize(B));
	printf("TreeleafSize: %d \r\n", Treeleafsize(C));

	LeveOrder(A);

	TreeDestory(A);

	return 0;
}






