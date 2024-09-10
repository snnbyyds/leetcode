/* https://leetcode.cn/problems/combination-sum/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes);
void backtrack(int **ans, int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int *path, int top, int path_sum, int startidx);

int main(void){
    int candidates[3] = {2, 3, 5};
    int target = 8;
    int returnSize;
    int *returnColumnSizes;
    int **ans = combinationSum(candidates, 3, target, &returnSize, &returnColumnSizes);
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

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int **ans = malloc(sizeof(int*) * 150);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 150);
    int *path = malloc(sizeof(int) * 20);
    backtrack(ans, candidates, candidatesSize, target, returnSize, returnColumnSizes, path, 0, 0, 0);
    return ans;
}

void backtrack(int **ans, int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int *path, int top, int path_sum, int startidx){
    if (path_sum == target)
    {
        ans[*returnSize] = malloc(sizeof(int) * top);
        (*returnColumnSizes)[*returnSize] = top;
        memcpy(ans[(*returnSize)++], path, sizeof(int) * top);
    }
    if (path_sum < target && top * 2 <= target)
    {
        for (int i = startidx; i < candidatesSize; i++)
        {
            path[top] = candidates[i];
            backtrack(ans, candidates, candidatesSize, target, returnSize, returnColumnSizes, path, top + 1, path_sum + candidates[i], i);
        }
    }
}