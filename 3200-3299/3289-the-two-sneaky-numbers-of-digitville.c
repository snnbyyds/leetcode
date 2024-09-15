/* https://leetcode.cn/problems/the-two-sneaky-numbers-of-digitville/ */

#include<stdio.h>
#include<stdlib.h>

int* getSneakyNumbers(int* nums, int numsSize, int* returnSize);

int main(void){
    int nums[] = {0, 3, 2, 1, 3, 2};
    int returnSize;
    int *ans = getSneakyNumbers(nums, 6, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d\t", ans[i]);
    }
    printf("\n");
    return 0;
}

int* getSneakyNumbers(int* nums, int numsSize, int* returnSize){
    int *map = calloc(101, sizeof(int));
    int *ans = malloc(2 * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++)
    {
        map[nums[i]]++;
        if (map[nums[i]] == 2)
        {
            ans[(*returnSize)++] = nums[i];
        }
    }
    return ans;
}