/* https://leetcode.cn/problems/4sum/ */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int **ans = malloc(numsSize * numsSize * sizeof(int));
    *returnColumnSizes = malloc(numsSize * numsSize * sizeof(int));

    int m = 0;
    long long sum;
    for (int left = 0; left < numsSize - 3; left++) {
        if (left > 0 && nums[left] == nums[left - 1]) {
            continue;
        }
        for (int idx1 = left + 1; idx1 < numsSize - 2; idx1++) {
            int idx2 = idx1 + 1;
            int right = numsSize - 1;
            if (idx1 > left + 1 && nums[idx1] == nums[idx1 - 1]) {
                continue;
            }
            while (idx2 < right) {
                sum = (long)nums[left] + nums[idx1] + nums[idx2] + nums[right];
                if (sum > target) {
                    right--;
                } else if (sum < target) {
                    idx2++;
                } else {
                    int *arr = malloc(4 * sizeof(int));
                    arr[0] = nums[left];
                    arr[1] = nums[idx1];
                    arr[2] = nums[idx2];
                    arr[3] = nums[right];
                    ans[m] = arr;
                    (*returnColumnSizes)[m] = 4;
                    m++;
                    for(idx2++; idx2 < right && nums[idx2] == nums[idx2 - 1]; idx2++);
                    for(right--; right > idx2 && nums[right] == nums[right + 1]; right--);
                }
            }
        }
    }
    *returnSize = m;
    return ans;
}

int main(void) {
    int nums[6] = {1, 0, -1, 0, -2, 2};
    int numsSize = 6;
    int returnSize;
    int *returnColumnSize;
    int **ans = fourSum(nums, numsSize, 0, &returnSize, &returnColumnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSize[i]; j++)
            printf("%d\t", ans[i][j]);
        printf("\n");
    }
    return 0;
}