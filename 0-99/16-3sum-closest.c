/* https://leetcode.cn/problems/3sum-closest */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int offset = INT_MAX;
    int ans;
    for (int left = 0; left <= numsSize - 2; left++) {
        int mid = left + 1;
        int right = numsSize - 1;
        while (mid < right) {
            int s = nums[left] + nums[mid] + nums[right];
            if (s == target) {
                return target;
            }
            if (s > target) {
                if (s - target < offset) {
                    offset = s - target;
                    ans = s;
                }
                right--;
            }
            else
            {
                if (target - s < offset) {
                    offset = target - s;
                    ans = s;
                }
                mid++;
            }
        }
    }
    return ans;
}

int main(void) {
    int nums[6] = {-1, 2, 1, -4};
    printf("%d\n", threeSumClosest(nums, 6, 1));
    return 0;
}