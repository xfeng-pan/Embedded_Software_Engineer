#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct HashNode
{
    int key;
    int count;
}HashNode;

int compare(const void* arg1, const void* arg2)
{
    return (*(HashNode*)arg2).count - (*(HashNode*)arg1).count;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    HashNode* map = (HashNode*)malloc(numsSize * sizeof(HashNode));
    if (map == NULL)
    {
        printf("map calloc failed!\r\n");
        exit(-1);
    }
    for (int i = 0; i < numsSize; i++)
    {
        map[i].key = 0;
        map[i].count = 0;
    }

    for (int i = 0; i < numsSize; i++)
    {
        map[nums[i]].key = nums[i];
        map[nums[i]].count++;
    }
    qsort(map, numsSize, sizeof(HashNode), compare);
    int* ret = (int*)malloc(sizeof(int) * k);
    if (ret == NULL)
    {
        printf("ret malloc failed!\r\n");
        exit(-1);
    }
    for (int i = 0; i < k; i++)
    {
        ret[i] = map[i].key;
    }
    free(map);
    map = NULL;
    *returnSize = k;
    return ret;
}

int main()
{
    int arr[] = { 3, 3, 1, 2, 2, 3 };
    int size = sizeof(arr)/sizeof(int);
    int k = 2;
    int res = 0;
    int* ret = topKFrequent(arr, size, k, &res);
    for (int i = 0; i < res; i++)
    {
        printf("ret[%d] = %d\r\n", i, ret[i]);
    }
    free(ret);
    ret = NULL;
    return 0;
}

