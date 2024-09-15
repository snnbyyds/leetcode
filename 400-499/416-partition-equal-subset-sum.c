/* https://leetcode.cn/problems/partition-equal-subset-sum/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<limits.h>

bool canPartition(int* nums, int numsSize);

int main(void){
    int nums[] = {1, 1, 1, 1};
    printf("%d\n", canPartition(nums, 4) ? 1 : 0);
    return 0;
}

bool canPartition(int* nums, int numsSize){
    int s = 0;
    for (int i = 0; i < numsSize; i++)
    {
        s += nums[i];
    }
    if (s % 2 != 0)
    {
        return false;
    }
    int target = s / 2;
    bool f[numsSize + 1][target + 1];
    memset(f, 0, sizeof(f));
    f[0][0] = true;
    for (int i = 0; i < numsSize; i++)
    {
        for (int t = 0; t <= target; t++)
        {
            if (t < nums[i])
            {
                f[i + 1][t] = f[i][t];
                continue;
            }
            f[i + 1][t] = f[i][t] || f[i][t - nums[i]];
        }
    }
    return f[numsSize][target];
}