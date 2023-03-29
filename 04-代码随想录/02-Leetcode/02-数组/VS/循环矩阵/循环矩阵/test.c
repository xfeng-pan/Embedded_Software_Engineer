#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


int** generateMatrix(int n) {
    //初始化计数器
    int count = 1;
    //初始化返回的结果数组的大小
    //*returnSize = n;
    //*returnColumnSizes = (int*)malloc(sizeof(int) * n);
    //初始化返回的结果数组ans
    int** arr = (int**)malloc(sizeof(int*) * n);
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int) * n);
        //(*returnColumnSizes)[i] = n;
    }
    for (int index = 0; index < n / 2; index++)
    {
        //从左到右
        for (int col1 = index; col1 < n - index; col1++)
        {
            arr[index][col1] = count;
            count++;
        }
        //从上到下
        for (int row1 = index; row1 < n - index; row1++)
        {
            arr[row1][n - index] = count;
            count++;
        }
        //从右到左
        for (int col2 = n - index; col2 > index; col2--)
        {
            arr[n - index][col2] = count;
            count++;
        }
        //从下到上
        for (int row2 = n - index; row2 > index; row2--)
        {
            arr[row2][index] = count;
            count++;
        }
    }
    //中间填充
    if (n % 2 == 1) arr[n / 2 + 1][n / 2 + 1] = count;
    return arr;

}


int main(void)
{
    int n = 3;

    int** res = generateMatrix(n);

    printf("end!!!\r\n");

}

//int** generateMatrix(int n)
//{
//	int** arr = (int**)malloc(n * sizeof(int*));//一个二级指针，每个指针指向的都是指向一个int类型的指针
//	int count = 1;//计数
//
//    for (int num = 0; num < n; num++)
//    {
//        arr[num] = (int*)malloc(n * sizeof(int));//二级指针指向的指针所指向的地址的大小
//
//    }
//
//    for (int index = 0; index < n / 2; index++)
//    {
//        for (int col1 = index; col1 < n - index; col1++)
//        {
//            arr[index][col1] = count;
//            count++;
//        }
//        for (int row1 = index; row1 < n - index; row1++)
//        {
//            arr[row1][n - index] = count;
//            count++;
//        }
//        for (int col2 = n - index; col2 > index; col2--)
//        {
//            arr[n - index][col2] = count;
//            count++;
//        }
//        for (int row2 = n - index; row2 > index; row2--)
//        {
//            arr[row2][index] = count;
//            count++;
//        }
//    }
//    if (n % 2 == 1) arr[n / 2 + 1][n / 2 + 1] = count;
//    return arr;
//
//}
//
//int main(void)
//{
//    int n = 3;
//    int** res = generateMatrix(n);
//
//    printf("end!!!\r\n");
//
//}
//
//
//
//
//
//
//
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
//    int** arr = (int**)malloc(n * sizeof(int*));
//    *returnSize = n;
//    *returnColumnSizes = (int*)malloc(n * sizeof(int*));
//    int count = 1;
//    for (int num = 0; num < n; num++)
//    {
//        arr[num] = (int*)malloc(n * sizeof(int));
//        (*returnColumnSizes)[num] = n;
//
//    }
//    for (int index = 0; index < n / 2; index++)
//    {
//        for (int col1 = index; col1 < n - index; col1++)
//        {
//            arr[index][col1] = count;
//            count++;
//        }
//        for (int row1 = index; row1 < n - index; row1++)
//        {
//            arr[row1][n - index] = count;
//            count++;
//        }
//        for (int col2 = n - index; col2 > index; col2--)
//        {
//            arr[n - index][col2] = count;
//            count++;
//        }
//        for (int row2 = n - index; row2 > index; row2--)
//        {
//            arr[row2][index] = count;
//            count++;
//        }
//    }
//    if (n % 2 == 1) arr[n / 2 + 1][n / 2 + 1] = count;
//    return arr;
//
//
//}