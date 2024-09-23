/* https://leetcode.cn/problems/maximum-number-of-operations-with-the-same-score-ii/ */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int maxOperations(int* nums, int numsSize);
int dfs(int *nums, int left, int right, int score, int numsSize, int (*cache)[][numsSize]);
int max(int a, int b, int c);

int main(void){
    int nums[] = {3, 2, 1, 2, 3, 4};
    printf("%d\n", maxOperations(nums, sizeof(nums) / sizeof(int)));
    return 0;
}

// dfs
int maxOperations(int* nums, int numsSize){
    int (*cache)[numsSize][numsSize] = malloc(sizeof(*cache));
    memset(*cache, 0x80, sizeof(*cache)); // -2139062144
    int case1 = dfs(nums, 0, numsSize - 1, nums[0] + nums[numsSize - 1], numsSize, cache);
    int case2;
    if (nums[numsSize - 1] == nums[1])
    {
        case2 = case1;
    }
    else
    {
        memset(*cache, 0x80, sizeof(*cache)); // -2139062144
        case2 = dfs(nums, 0, numsSize - 1, nums[0] + nums[1], numsSize, cache);
    }
    int case3;
    if (nums[numsSize - 2] == nums[0])
    {
        case3 = case1;
    }
    else if (nums[numsSize - 2] + nums[numsSize - 1] == nums[0] + nums[1])
    {
        case3 = case2;
    }
    else
    {
        memset(*cache, 0x80, sizeof(*cache)); // -2139062144
        case3 = dfs(nums, 0, numsSize - 1, nums[numsSize - 2] + nums[numsSize - 1], numsSize, cache);
    }
    free(cache);
    return max(case1, case2, case3);
}

int dfs(int *nums, int left, int right, int score, int numsSize, int (*cache)[][numsSize]){
    if (left >= right)
    {
        return 0;
    }
    if ((*cache)[left][right] != -2139062144)
    {
        return (*cache)[left][right];
    }
    int case1 = nums[left] + nums[right] == score ? dfs(nums, left + 1, right - 1, score, numsSize, cache) + 1 : 0;
    int case2 = nums[left] + nums[left + 1] == score ? dfs(nums, left + 2, right, score, numsSize, cache) + 1 : 0;
    int case3 = nums[right - 1] + nums[right] == score ? dfs(nums, left, right - 2, score, numsSize, cache) + 1 : 0;
    (*cache)[left][right] = max(case1, case2, case3);
    return (*cache)[left][right];
}

int max(int a, int b, int c){
    int ans = a > b ? a : b;
    ans = c > ans ? c : ans;
    return ans;
}

/*
int maxOperations(int* nums, int numsSize){
    int (*f)[numsSize + 2][numsSize + 2] = malloc(sizeof(*f));
    int scores[3];
    int scoresSize = 0;
    int score1 = nums[0] + nums[numsSize - 1];
    int score2 = nums[0] + nums[1];
    int score3 = nums[numsSize - 2] + nums[numsSize - 1];
    scores[scoresSize++] = score1;
    if (score2 != score1)
    {
        scores[scoresSize++] = score2;
    }
    if (score3 != scores[0] && score3 != scores[scoresSize - 1])
    {
        scores[scoresSize++] = score3;
    }
    int case1, case2, case3;
    int ret = INT_MIN;
    for (int i = 0; i < scoresSize; i++)
    {
        memset(*f, 0, sizeof(*f));
        for (int left = numsSize - 1; left >= 0; left--)
        {
            for (int right = left + 1; right < numsSize; right++)
            {
                case1 = nums[left] + nums[right] == scores[i] ? (*f)[left + 1][right + 1] + 1 : 0;
                case2 = nums[left] + nums[left + 1] == scores[i] ? (*f)[left + 2][right + 2] + 1 : 0;
                case3 = nums[right - 1] + nums[right] == scores[i] ? (*f)[left][right] + 1 : 0;
                (*f)[left][right + 2] = max(case1, case2, case3);
            }
        }
        ret = (*f)[0][numsSize + 1] > ret ? (*f)[0][numsSize + 1] : ret;
    }
    free(f);
    return ret;
}

int max(int a, int b, int c){
    int ans = a > b ? a : b;
    ans = c > ans ? c : ans;
    return ans;
}
*/