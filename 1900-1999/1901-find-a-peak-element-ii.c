/* https://leetcode.cn/problems/find-a-peak-element-ii/ */

#include<stdio.h>
#include<stdlib.h>

int* findPeakGrid(int** mat, int matSize, int* matColSize, int* returnSize);
int maxidx(int *arr, int arrSize);

int main(void){
    int **mat = malloc(3 * sizeof(int*));
    int arr0[3] = {10, 20, 15};
    int arr1[3] = {21, 30, 14};
    int arr2[3] = {7, 16, 25};
    mat[0] = arr0;
    mat[1] = arr1;
    mat[2] = arr2;
    int matColSize[3] = {3, 3, 3};
    int returnSize;
    int *ans = findPeakGrid(mat, 3, matColSize, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    free(mat);
    mat = NULL;
    return 0;
}

int* findPeakGrid(int** mat, int matSize, int* matColSize, int* returnSize){
    int left = 0;
    int right = matSize - 2;
    while (left <= right)
    {
        int i = (left + right) / 2;
        int j = maxidx(mat[i], matColSize[i]);
        if (mat[i][j] > mat[i + 1][j])
        {
            right = i - 1;
        }
        else
        {
            left = i + 1;
        }
    }
    int *ret = malloc(sizeof(int) * 2);
    *returnSize = 2;
    ret[0] = left;
    ret[1] = maxidx(mat[left], matColSize[left]);
    return ret;
}

int maxidx(int *arr, int arrSize){
    int idx = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > arr[idx])
        {
            idx = i;
        }
    }
    return idx;
}