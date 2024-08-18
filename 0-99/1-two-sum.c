/* https://leetcode.cn/problems/two-sum/ */

#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *p = malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++){
        for (int j = i + 1; j < numsSize; j++){
            if (target == nums[i] + nums[j]) {
                p[0] = i;
                p[1] = j;
                *returnSize = 2;
                return p;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main(void) {
    int nums[4] = {2,7,11,15};
    int returnSize;
    int *ans = twoSum(nums, 4, 9, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d\t", ans[i]);
    }
    printf("\n");
    return 0;
}