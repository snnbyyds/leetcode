/* https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/ */

#include<stdio.h>

int findMin(int* nums, int numsSize);

int main(void){
    int nums[5] = {3, 4, 5, 1, 2};
    printf("%d\n", findMin(nums, 5));
    return 0;
}

int findMin(int* nums, int numsSize){
    int left = 0;
    int right = numsSize - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] > nums[numsSize - 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return nums[left];
}