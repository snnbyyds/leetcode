/* https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/ */

#include<stdio.h>

int findMin(int* nums, int numsSize);

int main(void){
    int nums[7] = {2, 2, 3, 3, 0, 1, 2};
    printf("%d\n", findMin(nums, 7));
    return 0;
}

int findMin(int* nums, int numsSize){
    int left = 0;
    int right = numsSize - 2;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] > nums[right + 1])
        {
            left = mid + 1;
        }
        else if (nums[mid] < nums[right + 1])
        {
            right = mid - 1;
        }
        else
        {
            right--;
        }
    }
    return nums[left];
}