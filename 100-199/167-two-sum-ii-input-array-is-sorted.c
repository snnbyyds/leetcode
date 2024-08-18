/* https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/ */

#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0;
    int right = numbersSize - 1;
    *returnSize = 2;
    int *ans = malloc(2 * sizeof(int));
    while (left < right) {
        if (numbers[left] + numbers[right] == target) {
            ans[0] = left + 1;
            ans[1] = right + 1;
            return ans;
        } else if (numbers[left] + numbers[right] < target) {
            left++;
        } else {
            right--;
        }
    }
    ans[0] = -1;
    ans[1] = -1;
    return ans;
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