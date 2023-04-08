#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>



void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\r\n");
}

//ֱ�Ӳ�������
void InsertSort(int* a, int n)
{
	// a ������ָ�룬ָ������ͷ
	// n �������ڵ�Ԫ�������� ����±�Ϊ n - 1��
	// [0, end]������ģ� ��end + 1λ�õ�ֵ�����ȥ����[0, end + 1]����
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if(tmp > a[end]) // �������� 
			// if (tmp < a[end]) //��������
			{
				a[end + 1] = a[end];
				end--;
			}
			else break;
		}
		a[end + 1] = tmp;
	}
}

void TestInsertSort()
{
	int a[] = { 1,9,2,5,7,6,8,3,4 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 0)
	{
		gap /= 2;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])//���� //if (tmp < a[end])//����
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else break;
			}
			a[end + gap] = tmp;
		}
		
		//gap = gap/3 + 1;//��֤gap����ֵ��1
	}
}

void TestShellSort()
{
	int a[] = { 1,9,2,5,7,6,8,3,4 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1= *p2;
	*p2 = tmp;
}

//���µ����㷨
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;//Ĭ��ָ�����Ӵ�

	while (child < n)
	{
		if (child + 1 < n && a[child] > a[child + 1])//����Ƿ����Һ��ӣ����Ƚϴ�С
		{
			child += 1;
		}
		if (a[parent] > a[child]) //��С�� //����ѣ�if (a[parent] < a[child]),��һ��if�еıȽ�Ҳ��Ҫ�ı䷽��
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else break;
	}
}
// ������
void HeapSort(int* a, int n)
{
	//�����齨��С��
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//������Ҫ�����
	//�Ž���Ҫ��С��
	int end = n -1;
	while(end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}


}

//���������
void TestHeapSort()
{
	int a[] = { 1,9,2,5,7,6,8,3,4,0};
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


// ������������ܶԱ�
void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	//int begin3 = clock();
	//SelectSort(a3, N);
	//int end3 = clock();
	//int begin4 = clock();
	//HeapSort(a4, N);
	//int end4 = clock();
	//int begin5 = clock();
	//QuickSort(a5, 0, N - 1);
	//int end5 = clock();
	//int begin6 = clock();
	//MergeSort(a6, N);
	//int end6 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	//printf("SelectSort:%d\n", end3 - begin3);
	//printf("HeapSort:%d\n", end4 - begin4);
	//printf("QuickSort:%d\n", end5 - begin5);
	//printf("MergeSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}


int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestOP();
	TestHeapSort();
	return 0;
}




