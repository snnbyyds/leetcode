/* https://leetcode.cn/problems/permutations/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
void backtrack(int **ans, int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int *path, int top, bool *map);

int main(void){
    int nums[3] = {1, 2, 3};
    int returnSize;
    int *returnColumnSizes;
    int **ans = permute(nums, 3, &returnSize, &returnColumnSizes);
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

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int **ans = malloc(sizeof(int*) * 720);
    *returnColumnSizes = malloc(sizeof(int) * 720);
    int *path = malloc(sizeof(int) * numsSize);
    bool *map = calloc(21, sizeof(bool)); // records the selected
    backtrack(ans, nums, numsSize, returnSize, returnColumnSizes, path, 0, map);
    return ans;
}

void backtrack(int **ans, int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int *path, int top, bool *map){
    if (top == numsSize)
    {
        ans[*returnSize] = malloc(sizeof(int) * top);
        (*returnColumnSizes)[*returnSize] = top;
        memcpy(ans[(*returnSize)++], path, sizeof(int) * top);
        return;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (map[nums[i] + 10])
        {
            continue;
        }
        path[top] = nums[i];
        map[nums[i] + 10] = true;
        backtrack(ans, nums, numsSize, returnSize, returnColumnSizes, path, top + 1, map);
        map[nums[i] + 10] = false;
    }
}