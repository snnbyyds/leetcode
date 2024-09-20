/* https://leetcode.cn/problems/visit-array-positions-to-maximize-score/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long maxScore(int* nums, int numsSize, int x);
long long dfs(int *nums, int numSize, long long cache[][2], int x, int i, int j);
long long max(long long a, long long b);

int main(void){
    int nums[] = {2, 3, 6, 1, 9, 2};
    int x = 5;
    printf("%lld\n", maxScore(nums, sizeof(nums) / sizeof(int), x));
    return 0;
}

long long maxScore(int* nums, int numsSize, int x){
    long long cache[numsSize][2];
    memset(cache, 0x80, sizeof(cache)); // -9187201950435737472
    return dfs(nums, numsSize, cache, x, 0, nums[0] % 2);
}

// dfs(i, j) = max{dfs(i + 1, j), dfs(i + 1, j ^ 1) - x} + nums[i] 
long long dfs(int *nums, int numSize, long long cache[][2], int x, int i, int j){
    if (i >= numSize)
    {
        return 0;
    }
    if (cache[i][j] != -9187201950435737472)
    {
        return cache[i][j];
    }
    if (nums[i] % 2 != j)
    {
        cache[i][j] = dfs(nums, numSize, cache, x, i + 1, j);
        return cache[i][j];
    }
    cache[i][j] = max(dfs(nums, numSize, cache, x, i + 1, j), dfs(nums, numSize, cache, x, i + 1, j ^ 1) - x) + nums[i];
    return cache[i][j];
}

long long max(long long a, long long b){
    return a > b ? a : b;
}