/* https://leetcode.cn/problems/minimum-size-subarray-sum/ */

#include<stdio.h>
#include<stdint.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minSubArrayLen(int target, int* nums, int numsSize);

int main(void){
    int nums[6] = {2, 3, 1, 2, 4, 3};
    printf("%d\n", minSubArrayLen(7, nums, 6));
    return 0;
}

int minSubArrayLen(int target, int* nums, int numsSize){
    uint32_t sum = 0;
    uint32_t left = 0;
    uint32_t len = numsSize + 1;
    for (int right = 0; right < numsSize; right++)
    {
        sum += nums[right];
        while (sum >= target)
        {
            len = MIN(len, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return len <= numsSize ? len : 0;
}