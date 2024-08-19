/* https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/ */

#include<stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minOperations(int* nums, int numsSize, int x);

int main(void){
    int nums[5] = {1, 1, 4, 2, 3};
    int x = 5;
    printf("%d\n", minOperations(nums, 5, x));
    return 0;
}

int minOperations(int* nums, int numsSize, int x){
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }
    int t = sum - x;

    int left = 0;
    int s = 0;
    int op = numsSize + 1;
    for (int right = 0; right < numsSize; right++)
    {
        s += nums[right];
        while (s > t && left < right)
        {
            s -= nums[left];
            left++;
        }
        if (s == t)
        {
            op = MIN(op, numsSize - (right - left + 1));
        }
    }
    return op == numsSize + 1 ? -1 : op;
}