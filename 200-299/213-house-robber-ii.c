/* https://leetcode.cn/problems/house-robber-ii/ */

#include<stdio.h>

int rob(int* nums, int numsSize);
int func(int *nums, int numsSize);

int main(void){
    int nums[4] = {1, 2, 3, 1};
    printf("%d\n", rob(nums, 4));
    return 0;
}

int rob(int* nums, int numsSize){
    if (numsSize == 1)
    {
        return nums[0];
    }
    int case1 = func(nums, numsSize - 1);
    int case2 = func(nums + 1, numsSize - 1);
    return case1 > case2 ? case1 : case2;
}

int func(int *nums, int numsSize){
    int f0 = 0;
    int f1 = 0;
    int new_f;
    for (int i = 0; i < numsSize; i++)
    {
        new_f = f0 + nums[i] > f1 ? f0 + nums[i] : f1;
        f0 = f1;
        f1 = new_f;
    }
    return f1;
}