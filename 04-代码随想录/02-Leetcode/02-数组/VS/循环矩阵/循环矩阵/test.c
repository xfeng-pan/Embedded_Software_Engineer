#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


int** generateMatrix(int n) {
    //��ʼ��������
    int count = 1;
    //��ʼ�����صĽ������Ĵ�С
    //*returnSize = n;
    //*returnColumnSizes = (int*)malloc(sizeof(int) * n);
    //��ʼ�����صĽ������ans
    int** arr = (int**)malloc(sizeof(int*) * n);
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int) * n);
        //(*returnColumnSizes)[i] = n;
    }
    for (int index = 0; index < n / 2; index++)
    {
        //������
        for (int col1 = index; col1 < n - index; col1++)
        {
            arr[index][col1] = count;
            count++;
        }
        //���ϵ���
        for (int row1 = index; row1 < n - index; row1++)
        {
            arr[row1][n - index] = count;
            count++;
        }
        //���ҵ���
        for (int col2 = n - index; col2 > index; col2--)
        {
            arr[n - index][col2] = count;
            count++;
        }
        //���µ���
        for (int row2 = n - index; row2 > index; row2--)
        {
            arr[row2][index] = count;
            count++;
        }
    }
    //�м����
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
//	int** arr = (int**)malloc(n * sizeof(int*));//һ������ָ�룬ÿ��ָ��ָ��Ķ���ָ��һ��int���͵�ָ��
//	int count = 1;//����
//
//    for (int num = 0; num < n; num++)
//    {
//        arr[num] = (int*)malloc(n * sizeof(int));//����ָ��ָ���ָ����ָ��ĵ�ַ�Ĵ�С
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