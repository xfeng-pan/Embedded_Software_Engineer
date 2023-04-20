#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "Stack.h"




//打印数组
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\r\n");
}


//交换内存中的两个数
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
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
			//if(tmp > a[end]) // 降序排列 
			 if (tmp < a[end]) //升序排列
			{
				a[end + 1] = a[end];
				end--;
			}
			else break;
		}
		a[end + 1] = tmp;
	}
}

//直接插入排序测试
void TestInsertSort()
{
	int a[] = { 1,9,2,5,7,6,8,3,4 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


//希尔排序-直接插入排序的优化版本
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 0)
	{
		gap /= 2;//gap = gap / 3 + 1；两种方法最终都能让gap == 1；才能保证最后的排序是有序的。
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

//希尔排序测试
void TestShellSort()
{
	int a[] = { 1,9,2,5,7,6,8,3,4 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//直接选择排序
void SelectSort(int* a, int n)
{
	int begin = 0;
	for (; begin < n; begin++)
	{
		int min = begin;//升序排列
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

//直接选择排序测试
void SelectSortTest()
{
	int a[] = { 1,9,2,5,7,6,8,3,4 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//优化直接选择排序:在一次循环中找出这一轮循环的最大值和最小值；
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
		//如果begin和max重叠，则需要修正一下max的位置
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}
//优化直接选择排序测试
void OptimizSelectSortTest()
{
	int a[] = { 9,1,9,2,5,7,6,8,3,4,0 };
	OptimizeSelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}




//堆排序：
//1. 先编写向下调整算法
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
// 2. 堆排序 —— 建堆
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



// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int j = n; j > 1; j--)//第一趟冒泡排序需要
	{
		for (int i = 1; i < j; i++)//从1开始，防止越界
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
			}
		}
	}
}
//冒泡排序测试
void BubbleSortTest()
{
	int a[] = { 1,9,2,5,7,6,8,3,4,0 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
//冒泡排序优化
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
//优化冒泡排序测试
void OptimizeBubbleSortTest()
{
	int a[] = { 6,9,2,5,7,1,8,3,4,0 };
	OptimizeBubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


//三数取中
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

//快速排序——挖坑法
int PartSort1(int* a, int left, int right)
{
	//三数取中，避免最坏情况的出现
	int index = GetMid(a, left, right);
	Swap(&a[index], &a[left]);

	int begin = left, end = right;
	int pivot = begin;
	int key = a[begin];


	while (begin < end)
	{
		//右边找小的，放到左边
		while (begin < end && a[end] >= key)//除了找到比key小的数，还要保证end > begin
		{
			--end;
		}
		a[pivot] = a[end];//小的放到左边去，自己形成新的坑位
		pivot = end;
		//从左边找小的，放到右边
		while (begin < end && a[begin] <= key)//从左边找到比key大的数，同时要保证begin < end;
		{
			++begin;
		}
		a[pivot] = a[begin];//打的放到右边去，自己又形成新的坑位
		pivot = begin;
	}
	//当最后begin == end时，二者相遇了，坑就是begin，是end，此时将key放入坑中，完成一次排序
	pivot = begin;
	a[pivot] = key;

	return pivot;
}

//左右指针法
int PartSort2(int* a, int left, int right)
{
	//三数取中
	int mid = GetMid(a, left, right);
	Swap(&a[left], &a[mid]);

	int begin = left, end = right;
	int KeyIndex = begin;

	while (begin < end)
	{
		//从右往左找小
		while (begin < end && a[end] >= a[KeyIndex])
		{
			--end;
		}
		//从左往右找大
		while (begin < end && a[begin] <= a[KeyIndex])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[KeyIndex], &a[begin]);//交换相遇点与key的值
	return begin;
}

//前后指针法
int PartSort3(int* a, int left, int right)
{
	//三数取中
	int mid = GetMid(a, left, right);
	Swap(&a[mid], &a[left]);

	int prev = left;
	int cur = left + 1;
	int KeyIndex = left;

	while (cur <= right)
	{
		if (a[cur] < a[KeyIndex] && ++prev != cur) //找小的同时防止其自己跟自己交换
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[KeyIndex], &a[prev]);
	return prev;
}

//快速排序
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int KeyIndex = PartSort1(a, left, right);//挖坑法
	//int KeyIndex = PartSort2(a, left, right);//左右指针法
	//int KeyIndex = PartSort3(a, left, right);//左右指针法

	//到这里，原来数组的区间[left, right]已经被分为了三个部分
	// [left, pivot - 1], pivot, [pivot + 1, right]
	//类似于二叉树，需要使用递归进行求解
	//如果左子树和右子树都有序，则整体有序
	//因此可以利用分治算法，不理解是可以画递归展开图
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


//快速排序测试
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
	//将其分为两个区间：[left, mid], [mid + 1, right]
	//如果两个区间都是有序的，那么就可以进行归并排序了；
	//拆分
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp); 

	//归并
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

	//再将数据拷贝回int* a;
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



//非递归的快速排序
//利用数据结构的栈来模拟递归
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

	int gap = 1;//每组数据个数

	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[i, i + gap - 1] [i + gap, i + 2 * gap - 1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			//归并过程中右半区间可能不存在
			if (begin2 >= n)
			{
				break;
			}
			//归并过程中右半区间算多了
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
		//再将数据拷贝回int* a;
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




