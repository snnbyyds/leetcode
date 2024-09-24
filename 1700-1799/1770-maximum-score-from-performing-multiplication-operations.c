/* https://leetcode.cn/problems/maximum-score-from-performing-multiplication-operations/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int maximumScore(int* nums, int numsSize, int* multipliers, int multipliersSize);
int dfs(int *nums, int numsSize, int *multipliers, int multipliersSize, int (*cache)[][multipliersSize], int left, int multiplierIdx);
int max(int a, int b);

int main(void){
    int nums[6] = {-5, -3, -3, -2, 7, 1};
    int multipliers[5] = {-10, -5, 3, 4, 6};
    printf("%d\n", maximumScore(nums, 6, multipliers, 5));
    return 0;
}

int maximumScore(int* nums, int numsSize, int* multipliers, int multipliersSize){
    int (*cache)[numsSize][multipliersSize] = malloc(sizeof(*cache));
    memset(*cache, 0x80, sizeof(*cache)); // -2139062144
    int ret = dfs(nums, numsSize, multipliers, multipliersSize, cache, 0, 0);
    free(cache);
    return ret;
}

int dfs(int *nums, int numsSize, int *multipliers, int multipliersSize, int (*cache)[][multipliersSize], int left, int multiplierIdx){
    int right = left - multiplierIdx + numsSize - 1;
    if (left > right || multiplierIdx >= multipliersSize)
    {
        return 0;
    }
    if ((*cache)[left][multiplierIdx] != -2139062144)
    {
        return (*cache)[left][multiplierIdx];
    }
    int ret = max(dfs(nums, numsSize, multipliers, multipliersSize, cache, left + 1, multiplierIdx + 1) + nums[left] * multipliers[multiplierIdx], dfs(nums, numsSize, multipliers, multipliersSize, cache, left, multiplierIdx + 1) + nums[right] * multipliers[multiplierIdx]);
    (*cache)[left][multiplierIdx] = ret;
    return ret;
}

int max(int a, int b){
    return a > b ? a : b;
}