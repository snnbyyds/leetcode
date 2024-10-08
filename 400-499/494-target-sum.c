/* https://leetcode.cn/problems/target-sum/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findTargetSumWays(int* nums, int numsSize, int target);
// int dfs(int *nums, int i, int target, int cache[][4002]);

int main(void){
    int nums[] = {1, 1, 1, 1, 1};
    int target = 3;
    printf("%d\n", findTargetSumWays(nums, 5, target));
    return 0;
}

int findTargetSumWays(int* nums, int numsSize, int target){
    int s = 0;
    for (int i = 0; i < numsSize; i++)
    {
        s += nums[i];
    }
    if (s + target < 0 || (s + target) % 2 != 0)
    {
        return 0;
    }
    int c = (s + target) / 2;
    int f[21][1001];
    f[0][0] = 1;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            f[i + 1][j] = f[i][j] + (j < nums[i] ? 0 : f[i][j - nums[i]]);
        }
    }
    return f[numsSize][c];
}

/*
int findTargetSumWays(int* nums, int numsSize, int target){
    int cache[21][4002];
    memset(cache, 0, sizeof(cache));
    return dfs(nums, numsSize - 1, target, cache);
}

int dfs(int *nums, int i, int target, int cache[][4002]){
    if (i == 0)
    {
        return (nums[i] == target) + (nums[i] == -target);
    }
    if (cache[i][target + 2000] != 0)
    {
        return cache[i][target + 2000];
    }
    cache[i][target + 2000] = dfs(nums, i - 1, target - nums[i], cache) + dfs(nums, i - 1, target + nums[i], cache);
    return cache[i][target + 2000];
}
*/