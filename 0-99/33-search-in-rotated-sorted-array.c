/* https://leetcode.cn/problems/search-in-rotated-sorted-array/ */

#include<stdio.h>
#include<stdbool.h>

int search(int* nums, int numsSize, int target);
bool is_blue(int *nums, int numsSize, int idx, int target);

int main(void){
    int nums[7] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    printf("%d\n", search(nums, 7, target));
    return 0;
}

int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (is_blue(nums, numsSize, mid, target))
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

bool is_blue(int *nums, int numsSize, int idx, int target){
    if (target > nums[numsSize - 1])
    {
        return (nums[idx] < target && nums[idx] > nums[numsSize - 1]);
    }
    else
    {
        return (nums[idx] < target || nums[idx] > nums[numsSize - 1]);
    }
}