/* https://leetcode.cn/problems/subsets/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
void backtrack(int **ans, int *nums, int numsSize, int* returnSize, int **returnColumnSizes, int *path, int pathSize, int idx);

int main(void){
    int nums[3] = {1, 2, 3};
    int returnSize;
    int *returnColumnSizes;
    int **ans = subsets(nums, 3, &returnSize, &returnColumnSizes);
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

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int ansSize = pow(2, numsSize);
    int **ans = malloc(sizeof(int*) * ansSize);
    int *path = malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * ansSize);
    backtrack(ans, nums, numsSize, returnSize, returnColumnSizes, path, 0, 0);
    return ans;
}

void backtrack(int **ans, int *nums, int numsSize, int* returnSize, int **returnColumnSizes, int *path, int pathSize, int idx){
    ans[*returnSize] = malloc(sizeof(int) * pathSize);
    memcpy(ans[*returnSize], path, sizeof(int) * pathSize);
    (*returnColumnSizes)[(*returnSize)++] = pathSize;
    for (int i = idx; i < numsSize; i++)
    {
        path[pathSize] = nums[i];
        backtrack(ans, nums, numsSize, returnSize, returnColumnSizes, path, pathSize + 1, i + 1);
    }
}