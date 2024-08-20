/* https://leetcode.cn/problems/maximum-count-of-positive-integer-and-negative-integer/ */

#include<stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maximumCount(int* nums, int numsSize);
int lowbound(int *nums, int numsSize, int target);

int main(void){
    int nums[7] = {-3, -2, -1, 0, 0, 1, 2};
    printf("%d\n", maximumCount(nums, 7));
    return 0;
}

int maximumCount(int* nums, int numsSize){
    int target = 0;
    int lowpos = lowbound(nums, numsSize, target);
    int highneg = lowbound(nums, numsSize, target + 1) - 1;
    return MAX(lowpos, numsSize - 1 - highneg);
}

int lowbound(int *nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}