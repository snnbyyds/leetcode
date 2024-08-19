/* https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/ */

#include<stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long countSubarrays(int* nums, int numsSize, int k);
int maxinarray(int* nums, int numsSize);

int main(void){
    int nums[5] = {1, 3, 2, 3, 3};
    int k = 2;
    printf("%lld\n", countSubarrays(nums, 5, k));
    return 0;
}

long long countSubarrays(int* nums, int numsSize, int k){
    int cnt = 0;
    long long ans = 0;
    int left = 0;
    int max = maxinarray(nums, numsSize);
    for (int right = 0; right < numsSize; right++)
    {
        cnt += (nums[right] == max);
        while (cnt == k)
        {
            if (nums[left] == max)
            {
                cnt--;
            }
            left++;
        }
        ans += left;
    }
    
    return ans;
}

int maxinarray(int* nums, int numsSize){
    int max = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        max = MAX(max, nums[i]);
    }
    return max;
}