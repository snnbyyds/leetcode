/* https://leetcode.cn/problems/count-subarrays-with-score-less-than-k/ */

#include<stdio.h>

long long countSubarrays(int* nums, int numsSize, long long k);

int main(void){
    int nums[5] = {2, 1, 4, 3, 5};
    int k = 10;
    printf("%lld\n", countSubarrays(nums, 5, k));
    return 0;
}

long long countSubarrays(int* nums, int numsSize, long long k){
    int left = 0;
    long long ans = 0;
    long long sum = 0;
    for (int right = 0; right < numsSize; right++)
    {
        sum += nums[right];
        while (sum * (right - left + 1) >= k)
        {
            sum -= nums[left];
            left++;
        }
        ans += (right - left + 1);
    }
    return ans;
}