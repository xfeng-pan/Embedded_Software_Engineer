#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "Stack.h"




//��ӡ����
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\r\n");
}


//�����ڴ��е�������
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
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
			//if(tmp > a[end]) // �������� 
			 if (tmp < a[end]) //��������
			{
				a[end + 1] = a[end];
				end--;
			}
			else break;
		}
		a[end + 1] = tmp;
	}
}

//ֱ�Ӳ����������
void TestInsertSort()
{
	int a[] = { 1,9,2,5,7,6,8,3,4 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


//ϣ������-ֱ�Ӳ���������Ż��汾
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 0)
	{
		gap /= 2;//gap = gap / 3 + 1�����ַ������ն�����gap == 1�����ܱ�֤��������������ġ�
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

//ϣ���������
void TestShellSort()
{
	int a[] = { 1,9,2,5,7,6,8,3,4 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//ֱ��ѡ������
void SelectSort(int* a, int n)
{
	int begin = 0;
	for (; begin < n; begin++)
	{
		int min = begin;//��������
		for (int i = begin; i < n; i++)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		Swap(&a[begin], &a[min]);
	}
}

//ֱ��ѡ���������
void SelectSortTest()
{
	int a[] = { 1,9,2,5,7,6,8,3,4 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//�Ż�ֱ��ѡ������:��һ��ѭ�����ҳ���һ��ѭ�������ֵ����Сֵ��
void OptimizeSelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;

	while (begin < end)
	{
		int mini = begin, maxi = end;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		//���begin��max�ص�������Ҫ����һ��max��λ��
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}
//�Ż�ֱ��ѡ���������
void OptimizSelectSortTest()
{
	int a[] = { 9,1,9,2,5,7,6,8,3,4,0 };
	OptimizeSelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}




//������
//1. �ȱ�д���µ����㷨
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
// 2. ������ ���� ����
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



// ð������
void BubbleSort(int* a, int n)
{
	for (int j = n; j > 1; j--)//��һ��ð��������Ҫ
	{
		for (int i = 1; i < j; i++)//��1��ʼ����ֹԽ��
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
			}
		}
	}
}
//ð���������
void BubbleSortTest()
{
	int a[] = { 1,9,2,5,7,6,8,3,4,0 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
//ð�������Ż�
void OptimizeBubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		int exchange = 0;
		for (int i = 1; i < n - j; i++)
		{			
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}
//�Ż�ð���������
void OptimizeBubbleSortTest()
{
	int a[] = { 6,9,2,5,7,1,8,3,4,0 };
	OptimizeBubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


//����ȡ��
int GetMid(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if(a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if(a[right] > a[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

//�������򡪡��ڿӷ�
int PartSort1(int* a, int left, int right)
{
	//����ȡ�У����������ĳ���
	int index = GetMid(a, left, right);
	Swap(&a[index], &a[left]);

	int begin = left, end = right;
	int pivot = begin;
	int key = a[begin];


	while (begin < end)
	{
		//�ұ���С�ģ��ŵ����
		while (begin < end && a[end] >= key)//�����ҵ���keyС��������Ҫ��֤end > begin
		{
			--end;
		}
		a[pivot] = a[end];//С�ķŵ����ȥ���Լ��γ��µĿ�λ
		pivot = end;
		//�������С�ģ��ŵ��ұ�
		while (begin < end && a[begin] <= key)//������ҵ���key�������ͬʱҪ��֤begin < end;
		{
			++begin;
		}
		a[pivot] = a[begin];//��ķŵ��ұ�ȥ���Լ����γ��µĿ�λ
		pivot = begin;
	}
	//�����begin == endʱ�����������ˣ��Ӿ���begin����end����ʱ��key������У����һ������
	pivot = begin;
	a[pivot] = key;

	return pivot;
}

//����ָ�뷨
int PartSort2(int* a, int left, int right)
{
	//����ȡ��
	int mid = GetMid(a, left, right);
	Swap(&a[left], &a[mid]);

	int begin = left, end = right;
	int KeyIndex = begin;

	while (begin < end)
	{
		//����������С
		while (begin < end && a[end] >= a[KeyIndex])
		{
			--end;
		}
		//���������Ҵ�
		while (begin < end && a[begin] <= a[KeyIndex])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[KeyIndex], &a[begin]);//������������key��ֵ
	return begin;
}

//ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	//����ȡ��
	int mid = GetMid(a, left, right);
	Swap(&a[mid], &a[left]);

	int prev = left;
	int cur = left + 1;
	int KeyIndex = left;

	while (cur <= right)
	{
		if (a[cur] < a[KeyIndex] && ++prev != cur) //��С��ͬʱ��ֹ���Լ����Լ�����
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[KeyIndex], &a[prev]);
	return prev;
}

//��������
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int KeyIndex = PartSort1(a, left, right);//�ڿӷ�
	//int KeyIndex = PartSort2(a, left, right);//����ָ�뷨
	//int KeyIndex = PartSort3(a, left, right);//����ָ�뷨

	//�����ԭ�����������[left, right]�Ѿ�����Ϊ����������
	// [left, pivot - 1], pivot, [pivot + 1, right]
	//�����ڶ���������Ҫʹ�õݹ�������
	//���������������������������������
	//��˿������÷����㷨��������ǿ��Ի��ݹ�չ��ͼ
	if (KeyIndex - 1 - left > 10)
	{
		QuickSort(a, left, KeyIndex - 1);
	}
	else
	{
		InsertSort(a + left, KeyIndex -1 - left + 1);
	}

	if (right - (KeyIndex + 1) > 10)
	{
		QuickSort(a, KeyIndex + 1, right);
	}
	else
	{
		InsertSort(a + KeyIndex + 1, right - (KeyIndex +1) + 1);
	}
}


//�����������
void QuickSortTest()
{
	int a[] = { 6,9,2,5,7,1,8,3,4,0 };
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) >> 1;
	//�����Ϊ�������䣺[left, mid], [mid + 1, right]
	//����������䶼������ģ���ô�Ϳ��Խ��й鲢�����ˣ�
	//���
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp); 

	//�鲢
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	//�ٽ����ݿ�����int* a;
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}

}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc failed\r\n");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}

void MergeSortTest()
{
	int a[] = { 6,9,2,5,7,1,8,3,4,0 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}



//�ǵݹ�Ŀ�������
//�������ݽṹ��ջ��ģ��ݹ�
void QuickSortNonR(int* a, int n)
{
	ST st;
	StackInit(&st);
	StackPush(&st, n - 1);
	StackPush(&st, 0);

	while (!IsStackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);

		int right = StackTop(&st);
		StackPop(&st);

		int KeyIndex = PartSort3(a, left, right);
		// [left, KeyIndex - 1], KeyIndex, [KeyIndex + 1, right]
		if (KeyIndex + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, KeyIndex);
		}

		if (left < KeyIndex - 1)
		{
			StackPush(&st, KeyIndex);
			StackPush(&st, left);
		}
	}
	StackDestory(&st);
}


void QuickSortNonRTest()
{
	int a[] = { 6,9,2,5,7,1,8,3,4,0 };
	QuickSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


void MergeSortNorR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	int gap = 1;//ÿ�����ݸ���

	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[i, i + gap - 1] [i + gap, i + 2 * gap - 1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			//�鲢�������Ұ�������ܲ�����
			if (begin2 >= n)
			{
				break;
			}
			//�鲢�������Ұ����������
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			int index = i;

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}
			
		}
		//�ٽ����ݿ�����int* a;
		for (int j = 0; j < n; j++)
		{
			a[j] = tmp[j];
		}
		gap *= 2;
	}
}

void MergeSortNorRTest()
{
	int a[] = { 6,9,2,5,7,1,8,3,4,0 };
	MergeSortNorR(a, sizeof(a) / sizeof(int));
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
	int* a7 = (int*)malloc(sizeof(int) * N);
	int* a8 = (int*)malloc(sizeof(int) * N);
	int* a9 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
		a9[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();

	int beginoss = clock();
	OptimizeSelectSort(a7, N);
	int endoss = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int beginbs = clock();
	BubbleSort(a8, N);
	int endbs = clock();

	int beginobs = clock();
	OptimizeBubbleSort(a9, N);
	int endobs = clock();
	

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	

	//int begin6 = clock();
	//MergeSort(a6, N);
	//int end6 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("OptimizeSelectSort:%d\n", endoss - beginoss);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("BubbleSort:%d\n", endbs - beginbs);
	printf("OptimizeBubbleSort:%d\n", endobs - beginobs);
	printf("QuickSort:%d\n", end5 - begin5);
	//printf("MergeSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
	free(a9);
}


int main()
{
	//TestInsertSort();
	 
	//TestShellSort();
	 
	//SelectSortTest();
	//OptimizSelectSortTest();
	 
	//TestHeapSort();

	//BubbleSortTest();
	//OptimizeBubbleSortTest();

	//QuickSortTest();

	//MergeSortTest();

	//QuickSortNonRTest();

	MergeSortNorRTest();

	//TestOP();
	return 0;
}




