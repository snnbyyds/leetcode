/* https://leetcode.cn/problems/count-the-number-of-fair-pairs/ */

#include<stdio.h>
#include<stdlib.h>

long long countFairPairs(int* nums, int numsSize, int lower, int upper);
int cmp(const void *a, const void *b);
int getlowbound(int *nums, int right, int target);

int main(void){
    int nums[6] = {0, 1, 7, 4, 4, 5};
    int lower = 3;
    int upper = 6;
    printf("%lld\n", countFairPairs(nums, 6, lower, upper));
    return 0;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper){
    qsort(nums, numsSize, sizeof(int), cmp);
    int low, high;
    long long cnt = 0;
    for (int j = 0; j < numsSize; j++)
    {
        low = getlowbound(nums, j - 1, lower - nums[j]);
        high = getlowbound(nums, j - 1, upper - nums[j] + 1);
        cnt += (high - low);
    }
    return cnt;
}

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int getlowbound(int *nums, int right, int target){
    int left = 0;
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