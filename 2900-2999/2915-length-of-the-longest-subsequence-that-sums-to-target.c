/* https://leetcode.cn/problems/length-of-the-longest-subsequence-that-sums-to-target/ */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubsequence(int* nums, int numsSize, int target);
// int dfs(int *nums, int i, int t, int cache[][1002]);

int main(void){
    int nums[6] = {4, 1, 3, 2, 1, 5};
    int target = 7;
    printf("%d\n", lengthOfLongestSubsequence(nums, 6, target));
    return 0;
}

// dp

int lengthOfLongestSubsequence(int* nums, int numsSize, int target){
    int f[1002][1002];
    memset(f, -1, sizeof(f));
    f[0][0] = 0;
    for (int t = 1; t <= target; t++)
    {
        f[0][t] = INT_MIN;
    }
    for (int i = 0; i < numsSize; i++)
    {
        for (int t = 0; t <= target; t++)
        {
            if (t - nums[i] < 0)
            {
                f[i + 1][t] = f[i][t];
                continue;
            }
            f[i + 1][t] = MAX(f[i][t], f[i][t - nums[i]] + 1);
        }
    }
    return f[numsSize][target] < 0 ? -1 : f[numsSize][target];
}

// dfs

/*
int lengthOfLongestSubsequence(int* nums, int numsSize, int target){
    int cache[1002][1002];
    memset(cache, -1, sizeof(cache));
    int res = dfs(nums, numsSize - 1, target, cache);
    return res <= 0 ? -1 : res;
}

int dfs(int *nums, int i, int t, int cache[][1002]){
    if (i < 0)
    {
        if (t == 0)
        {
            return 0;
        }
        return INT_MIN;
    }
    if (cache[i][t] > -1)
    {
        return cache[i][t];
    }
    if (t - nums[i] < 0)
    {
        return dfs(nums, i - 1, t, cache);
    }
    int c1 = dfs(nums, i - 1, t, cache);
    int c2 = dfs(nums, i - 1, t - nums[i], cache) + 1;
    cache[i][t] = c1 > c2 ? c1 : c2;
    return cache[i][t]; 
}
*/