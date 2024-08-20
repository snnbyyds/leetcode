/* https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/ */

#include<stdio.h>
#include<stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize);
int lowbound(int *nums, int numsSize, int target);

int main(void){
    int nums[6] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int returnSize;
    int *ans = searchRange(nums, 6, target, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    free(ans);
    return 0;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *ans = malloc(sizeof(int) * 2);
    int low = lowbound(nums, numsSize, target);
    if (low == numsSize || nums[low] != target)
    {
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }
    int high = lowbound(nums, numsSize, target + 1) - 1;
    ans[0] = low;
    ans[1] = high;
    return ans;
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