/* https://leetcode.cn/problems/combinations/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int** combine(int n, int k, int* returnSize, int** returnColumnSizes);
void backtrack(int **ans, int n, int k, int* returnSize, int** returnColumnSizes, int *path, int top, int startidx);

int main(void){
    int n = 4;
    int k = 2;
    int returnSize;
    int *returnColumnSizes;
    int **ans = combine(n, k, &returnSize, &returnColumnSizes);
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

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int **ans = malloc(sizeof(int *) * 184756); // 184756 == 20C10
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 184756);
    int *path = malloc(sizeof(int) * k);
    backtrack(ans, n, k, returnSize, returnColumnSizes, path, 0, 1);
    return ans;
}

void backtrack(int **ans, int n, int k, int* returnSize, int** returnColumnSizes, int *path, int top, int startidx){
    if (top == k)
    {
        ans[*returnSize] = malloc(sizeof(int) * k);
        memcpy(ans[*returnSize], path, sizeof(int) * k);
        (*returnColumnSizes)[(*returnSize)++] = k;
        return;
    }
    for (int i = startidx; i <= n - k + top + 1; i++)
    {
        path[top] = i;
        backtrack(ans, n, k, returnSize, returnColumnSizes, path, top + 1, i + 1);
    }
}