/* https://leetcode.cn/problems/combination-sum-iii/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes);
void backtrack(int **ans, int k, int n, int* returnSize, int** returnColumnSizes, int *path, int top, int startidx, int remain);
bool validpath(int *path, int top, int n);

int main(void){
    int k = 3;
    int n = 9;
    int returnSize;
    int *returnColumnSizes;
    int **ans = combinationSum3(k, n, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d\t", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int **ans = malloc(sizeof(int*) * 126);
    *returnColumnSizes = malloc(sizeof(int) * 126);
    int *path = malloc(sizeof(int) * k);
    backtrack(ans, k, n, returnSize, returnColumnSizes, path, 0, 1, n);
    return ans;
}

void backtrack(int **ans, int k, int n, int* returnSize, int** returnColumnSizes, int *path, int top, int startidx, int remain){
    if (k - top < 0) {
        return;
    }
    if (k == top)
    {
        if (validpath(path, top, n))
        {
            ans[*returnSize] = malloc(sizeof(int) * k);
            (*returnColumnSizes)[*returnSize] = k;
            memcpy(ans[(*returnSize)++], path, sizeof(int) * k);
        }
        return;
    }
    for (int i = startidx; i <= 9; i++)
    {
        path[top] = i;
        backtrack(ans, k, n, returnSize, returnColumnSizes, path, top + 1, i + 1, n - i);
    }
}

bool validpath(int *path, int top, int n){
    int sum = 0;
    for (int i = 0; i < top; i++)
    {
        sum += path[i];
    }
    return sum == n;
}