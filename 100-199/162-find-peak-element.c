/* https://leetcode.cn/problems/find-peak-element/ */

#include<stdio.h>

int findPeakElement(int* nums, int numsSize);

int main(void){
    int nums[7] = {1, 2, 1, 3, 5, 6, 4};
    printf("%d\n", findPeakElement(nums, 7));
    return 0;
}

int findPeakElement(int* nums, int numsSize){
    int left = 0;
    int right = numsSize - 2;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] < nums[mid + 1])
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