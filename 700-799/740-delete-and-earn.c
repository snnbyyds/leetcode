/* https://leetcode.cn/problems/delete-and-earn/ */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

int deleteAndEarn(int* nums, int numsSize);

int main(void){
    int nums[6] = {2, 2, 3, 3, 3, 4};
    printf("%d\n", deleteAndEarn(nums, 6));
    return 0;
}

int deleteAndEarn(int* nums, int numsSize){
    int min = INT_MAX;
    int max = INT_MIN;
    int *map = calloc(10002, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < min)
        {
            min = nums[i];
        }
        if (nums[i] > max)
        {
            max = nums[i];
        }
        map[nums[i]]++;
    }
    int f0 = min * map[min];
    int f1 = fmax(f0, (min + 1) * map[min + 1]);
    int new_f;
    for (int i = min + 2; i <= max; i++)
    {
        new_f = fmax(f1, f0 + i * map[i]);
        f0 = f1;
        f1 = new_f;
    }
    return f1;
}