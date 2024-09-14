/* https://leetcode.cn/problems/combination-sum-iv/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int combinationSum4(int* nums, int numsSize, int target);

int main(void){
    int nums[3] = {1, 2, 3};
    int target = 4;
    printf("%d\n", combinationSum4(nums, 3, target));
    return 0;
}

int combinationSum4(int* nums, int numsSize, int target){
    unsigned int *f = malloc(sizeof(unsigned int) * (target + 1));
    f[0] = 1;
    for (int t = 1; t <= target; t++)
    {
        f[t] = 0;
        for (int i = 0; i < numsSize; i++)
        {
            f[t] += t - nums[i] >= 0 ? f[t - nums[i]] : 0;
        }
    }
    return f[target];
}

/*
int combinationSum4(int* nums, int numsSize, int target);
int dfs(int* nums, int numsSize, int target, int *cache);

int main(void){
    int nums[3] = {1, 2, 3};
    int target = 4;
    printf("%d\n", combinationSum4(nums, 3, target));
    return 0;
}

int combinationSum4(int* nums, int numsSize, int target){
    int *cache = malloc(sizeof(int) * (target + 1));
    for (int i = 0; i < target + 1; i++)
    {
        cache[i] = -1;
    }
    return dfs(nums, numsSize, target, cache);
}

int dfs(int* nums, int numsSize, int target, int *cache){
    if (target == 0)
    {
        return 1;
    }
    if (cache[target] != -1)
    {
        return cache[target];
    }
    int res = 0;
    for (int i = 0; i < numsSize; i++)
    {
        res += target - nums[i] >= 0 ? dfs(nums, numsSize, target - nums[i], cache) : 0;
    }
    cache[target] = res;
    return res;
}
*/