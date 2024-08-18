/* https://leetcode.cn/problems/valid-triangle-number/ */

#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int triangleNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int cnt = 0;
    for (int right = 2; right < numsSize; right++) {
        int left = 0;
        int mid = right - 1;
        while (left < mid) {
            if (nums[left] + nums[mid] > nums[right]) {
                cnt += mid - left;
                mid--;
            } else {
                left++;
            }
        }
    }
    return cnt;
}

int main(void) {
    int nums[4] = {4, 2, 3, 4};
    printf("%d\n", triangleNumber(nums, 4));
    return 0;
}