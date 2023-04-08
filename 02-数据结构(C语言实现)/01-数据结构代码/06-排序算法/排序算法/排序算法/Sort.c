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

//直接插入排序
void InsertSort(int* a, int n)
{
	// a 是数组指针，指向数组头
	// n 是数组内的元素数量， 最大下标为 n - 1；
	// [0, end]是有序的， 将end + 1位置的值插入进去，让[0, end + 1]有序
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if(tmp > a[end]) // 降序排列 
			// if (tmp < a[end]) //升序排列
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
				if (tmp < a[end])//升序 //if (tmp < a[end])//降序
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else break;
			}
			a[end + gap] = tmp;
		}
		
		//gap = gap/3 + 1;//保证gap最后的值是1
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

//向下调整算法
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;//默认指向左子代

	while (child < n)
	{
		if (child + 1 < n && a[child] > a[child + 1])//检测是否有右孩子，并比较大小
		{
			child += 1;
		}
		if (a[parent] > a[child]) //建小堆 //建大堆：if (a[parent] < a[child]),上一个if中的比较也需要改变方向
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else break;
	}
}
// 堆排序
void HeapSort(int* a, int n)
{
	//把数组建成小堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//排升序：要建大堆
	//排降序：要建小堆
	int end = n -1;
	while(end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}


}

//堆排序测试
void TestHeapSort()
{
	int a[] = { 1,9,2,5,7,6,8,3,4,0};
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


// 测试排序的性能对比
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




