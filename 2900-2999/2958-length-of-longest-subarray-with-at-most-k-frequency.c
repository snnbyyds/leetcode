/* https://leetcode.cn/problems/length-of-longest-subarray-with-at-most-k-frequency */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSubarrayLength(int* nums, int numsSize, int k);
int maxinarray(int *array, int len);

int main(void){
    int k = 2;
    int array[8] = {1, 2, 3, 1, 2, 3, 1, 2};
    printf("%d\n", maxSubarrayLength(array, 8, k));
    return 0;
}

int maxSubarrayLength(int* nums, int numsSize, int k){
    int ans = 0;
    int left = 0;

    int max = maxinarray(nums, numsSize);
    int *arr = calloc(max + 1, sizeof(int));

    for (int right = 0; right < numsSize; right++)
    {
        arr[nums[right]]++;
        while (arr[nums[right]] > k)
        {
            arr[nums[left]]--;
            left++;
        }
        ans = MAX(ans, right - left + 1);
    }
    return ans;
}

int maxinarray(int *array, int len){
    int max = array[0];
    for (int i = 1; i < len; i++)
    {
        max = MAX(max, array[i]);
    }
    return max;
}