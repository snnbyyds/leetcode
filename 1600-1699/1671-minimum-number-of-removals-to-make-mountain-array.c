/* https://leetcode.cn/problems/minimum-number-of-removals-to-make-mountain-array/ */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int minimumMountainRemovals(int* nums, int numsSize);

int main(void){
    int nums[] = {100, 92, 89, 77, 74, 66, 64, 66, 64};
    printf("%d\n", minimumMountainRemovals(nums, sizeof(nums) / sizeof(int)));
    return 0;
}

// dp
int minimumMountainRemovals(int* nums, int numsSize){
    int *f = malloc(sizeof(int) * numsSize);
    int *g = malloc(sizeof(int) * numsSize);
    int len = 3;
    for (int i = 0; i < numsSize; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                if (f[j] + 1 > f[i])
                {
                    f[i] = f[j] + 1;
                }
            }
        }
    }
    for (int i = numsSize - 1; i >= 0; i--)
    {
        g[i] = 1;
        for (int j = numsSize - 1; j > i; j--)
        {
            if (nums[j] < nums[i])
            {
                if (g[j] + 1 > g[i])
                {
                    g[i] = g[j] + 1;
                }
            }
        }
        if (f[i] >= 2 && g[i] >= 2 && len < g[i] + f[i] - 1)
        {
            len = g[i] + f[i] - 1;
        }
    }
    free(f);
    free(g);
    return numsSize - len;
}