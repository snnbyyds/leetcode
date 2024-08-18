/* https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target/ */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int countPairs(int* nums, int numsSize, int target){
    // sort nums with qsort()
    qsort(nums, numsSize, sizeof(int), cmp);

    uint32_t left = 0;
    uint32_t right = numsSize - 1;
    uint32_t cnt = 0;

    while (left < right) {
        if (nums[left] + nums[right] < target) {
            cnt += right - left;
            left++;
        } else {
            right--;
        }
    }

    return cnt;
}

int main(void) {
    int target = 2;
    int nums[5] = {-1, 1, 2, 3, 1};
    int numsSize = 5;
    printf("%d\n", countPairs(nums, numsSize, target));
    return 0;
}