/* https://leetcode.cn/problems/3sum/ */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // sort with qsort()
    qsort(nums, numsSize, sizeof(int), cmp);

    // do malloc;
    int** ans = malloc(numsSize * numsSize * sizeof(int*));
    *returnColumnSizes = malloc(numsSize * numsSize * sizeof(int));

    int m = 0;

    for (int left = 0; left < numsSize - 2; left++) {
        if (left > 0 && nums[left] == nums[left - 1]) {
            continue;
        }
        if (nums[left] + nums[left + 1] + nums[left + 2] > 0) {
            break;
        }
        if (nums[left] + nums[numsSize - 1] + nums[numsSize - 2] < 0) {
            continue;
        }
        int mid = left + 1;
        int right = numsSize - 1;
        while (mid < right) {
            int s = nums[left] + nums[mid] + nums[right];
            if (s > 0) {
                right--;
            } else if (s < 0) {
                mid++;
            } else { // s == 0
                int *arr = malloc(3 * sizeof(int));
                arr[0] = nums[left];
                arr[1] = nums[mid];
                arr[2] = nums[right];
                ans[m] = arr;
                (*returnColumnSizes)[m] = 3;
                m++;
                for (mid++; mid < right && nums[mid] == nums[mid - 1]; mid++);
                for (right--; right > mid && nums[right] == nums[right + 1]; right--);
            }
        }
    }
    *returnSize = m;
    return ans;
}

int main(void) {
    int nums[6] = {-1, 0, 1, 2, -1, -4};
    int numsSize = 6;
    int returnSize;
    int *returnColumnSize;
    int **ans = threeSum(nums, numsSize, &returnSize, &returnColumnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSize[i]; j++)
            printf("%d\t", ans[i][j]);
        printf("\n");
    }
    return 0;
}