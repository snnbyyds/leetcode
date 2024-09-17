/* https://leetcode.cn/problems/number-of-longest-increasing-subsequence/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int findNumberOfLIS(int* nums, int numsSize);

int main(void){
    // int nums[] = {1, 3, 5, 4, 7};
    int nums[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    printf("%d\n", findNumberOfLIS(nums, sizeof(nums) / sizeof(int)));
    return 0;
}

// dp
int findNumberOfLIS(int* nums, int numsSize){
    int ans = 0;
    int *f = malloc(sizeof(int) * numsSize);
    int *cnt = malloc(sizeof(int) * numsSize);
    int max = 0;
    for (int i = 0; i < numsSize; i++)
    {
        f[i] = 1;
        cnt[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                if (f[j] + 1 > f[i])
                {
                    f[i] = f[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if (f[j] + 1 == f[i])
                {
                    cnt[i] += cnt[j];
                }
            }
        }
        if (f[i] > max)
        {
            max = f[i];
            ans = cnt[i];
        }
        else if (f[i] == max)
        {
            ans += cnt[i];
        }
    }
    free(f);
    free(cnt);
    return ans;
}