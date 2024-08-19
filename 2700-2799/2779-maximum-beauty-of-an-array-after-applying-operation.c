/* https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation/ */

#include<stdio.h>
#include<stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maximumBeauty(int* nums, int numsSize, int k);

int cmp(const void* a, const void* b);

int main(void){
    int nums[4] = {4, 6, 1, 2};
    int len = 4;
    int k = 2;
    printf("%d\n", maximumBeauty(nums, len, k));
    return 0;
}

int maximumBeauty(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), cmp);

    int left = 0;
    int ans = 0;
    for (int right = 0; right < numsSize; right++)
    {
        while (nums[right] - nums[left] > 2 * k)
        {
            left++;
        }
        ans = MAX(right - left + 1, ans);
    }
    return ans;
}

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}