/* https://leetcode.cn/problems/longest-increasing-subsequence/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int lengthOfLIS(int* nums, int numsSize);
void write_g(int *g, int *top, int num);
// int dfs(int *nums, int x, int *cache);

int main(void){
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    printf("%d\n", lengthOfLIS(nums, sizeof(nums) / sizeof(int)));
    return 0;
}

int lengthOfLIS(int* nums, int numsSize){
    int *g = malloc(sizeof(int) * numsSize);
    g[0] = nums[0];
    int top = 1;
    for (int i = 1; i < numsSize; i++)
    {
        write_g(g, &top, nums[i]);
    }
    free(g);
    return top;
}

void write_g(int *g, int *top, int num){
    if (g[(*top) - 1] < num)
    {
        g[(*top)++] = num;
        return;
    }
    int left = 0;
    int right = (*top) - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (g[mid] < num)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    g[left] = num;
}

// dp
/*
int lengthOfLIS(int* nums, int numsSize){
    int *f = malloc(sizeof(int) * numsSize);
    memset(f, -1, sizeof(int) * numsSize);
    f[0] = 1;
    int max;
    for (int i = 1; i < numsSize; i++)
    {
        max = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                max = (int)fmax(max, f[j]);
            }
        }
        f[i] = max + 1;
    }
    max = 0;
    for (int i = 0; i < numsSize; i++)
    {
        max = fmax(max, f[i]);
    }
    free(f);
    return max;
}
*/

// dfs

// dfs(i) = max{dfs(j), ...} + 1    j < i && nums[j] < nums[i]
// ans = max{dfs(i), dfs(j), ...}

/*
int lengthOfLIS(int* nums, int numsSize){
    int *cache = malloc(sizeof(int) * numsSize);
    memset(cache, -1, sizeof(int) * numsSize);
    cache[0] = 1;
    int max = 0;
    for (int i = 0; i < numsSize; i++)
    {
        max = (int)fmax(dfs(nums, i, cache), max);
    }
    free(cache);
    return max;
}

int dfs(int *nums, int x, int *cache){
    if (cache[x] != -1)
    {
        return cache[x];
    }
    int max = 0;
    for (int i = 0; i < x; i++)
    {
        if (nums[i] < nums[x])
        {
            max = (int)fmax(dfs(nums, i, cache), max);
        }
    }
    cache[x] = max + 1;
    return cache[x];
}
*/