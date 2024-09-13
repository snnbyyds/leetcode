/* https://leetcode.cn/problems/house-robber/ */

#include<stdio.h>
#include<stdlib.h>

int rob(int* nums, int numsSize);
/*
int dfs(int *nums, int i, int *cache);
*/

int main(void){
    int nums[5] = {2, 7, 9, 3, 1};
    printf("%d\n", rob(nums, 5));
    return 0;
}

int rob(int* nums, int numsSize){
    int *f = calloc(numsSize + 2, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        f[i + 2] = f[i] + nums[i] > f[i + 1] ? f[i] + nums[i] : f[i + 1];
    }
    return f[numsSize + 1];
    /*
    int *cache = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        cache[i] = -1;
    }
    return dfs(nums, numsSize - 1, cache);
    */
}

/*
int dfs(int *nums, int i, int *cache){
    if (i < 0)
    {
        return 0;
    }
    if (cache[i] != -1)
    {
        return cache[i];
    }
    int l = dfs(nums, i - 1, cache);
    int r = dfs(nums, i - 2, cache) + nums[i];
    int res = r > l ? r : l;
    cache[i] = res;
    return res;
}
*/