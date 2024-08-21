/* https://leetcode.cn/problems/minimize-maximum-of-array/ */

#include<stdio.h>
#include<stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minimizeArrayValue(int* nums, int numsSize);
long long operation(int limit, int *nums, int numsSize);

int main(void){
    int nums[4] = {3, 7, 1, 6};
    printf("%d\n", minimizeArrayValue(nums, 4));
    return 0;
}

int minimizeArrayValue(int* nums, int numsSize){
    int left = -1;
    int right = 0;
    for (int i = 0; i < numsSize; i++)
    {
        right = MAX(right, nums[i]);
    }
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (operation(mid, nums, numsSize) <= mid)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        
    }
    return left;
}

long long operation(int limit, int *nums, int numsSize){
    long long delta;
    long long *p = malloc(numsSize * sizeof(long long));
    for (int i = 0; i < numsSize; i++)
    {
        p[i] = (long long)nums[i];
    }
    
    for (int i = numsSize - 1; i >= 1; i--)
    {
        delta = p[i] - limit;
        if (delta > 0)
        {
            p[i] = limit;
            p[i - 1] += delta;
        }
    }
    long long res = p[0];
    free(p);
    return res;
}