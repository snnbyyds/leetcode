/* https://leetcode.cn/problems/subarray-product-less-than-k/ */

#include<stdio.h>
#include<stdint.h>

int numSubarrayProductLessThanK(int* nums, int numsSize, int k);

int main(void){
    int nums[4] = {10, 5, 2, 6};
    printf("%d\n", numSubarrayProductLessThanK(nums, 4, 100));
    return 0;
}

int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    uint32_t left = 0;
    int pro = 1;
    uint32_t cnt = 0;
    for (uint32_t right = 0; right < numsSize; right++)
    {
        pro *= nums[right];
        while (pro >= k && left <= right)
        {
            pro /= nums[left];
            left++;
        }
        if (pro < k)
        {
            cnt += (right - left + 1);
        }
    }
    return cnt;
}