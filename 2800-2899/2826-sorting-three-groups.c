/* https://leetcode.cn/problems/sorting-three-groups/ */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int minimumOperations(int* nums, int numsSize);
void write_g(int *g, int *top, int num);

int main(void){
    int nums[] = {2, 1, 3, 2, 1};
    printf("%d\n", minimumOperations(nums, sizeof(nums) / sizeof(int)));
    return 0;
}

int minimumOperations(int* nums, int numsSize){
    // get the longest non-decreasing child first
    int *g = malloc(sizeof(int) * numsSize);
    g[0] = nums[0];
    int top = 1;
    for (int i = 1; i < numsSize; i++)
    {
        write_g(g, &top, nums[i]);
    }
    // free and return
    free(g);
    return numsSize - top;
}

void write_g(int *g, int *top, int num){
    if (g[(*top) - 1] <= num)
    {
        g[(*top)++] = num;
        return;
    }
    // do bsearch and write
    int left = 0;
    int right = (*top) - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (num < g[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    g[left] = num;
}

// dp
// get the longest non-decreasing child first

// f(i) = max{f(j), ...} + 1    j < i && nums[j] <= nums[i]
// ans = max{f(i), f(j), ...}

/*
int minimumOperations(int* nums, int numsSize){
    int max_len = 0;
    int *f = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] <= nums[i])
            {
                if (f[j] + 1 > f[i])
                {
                    f[i] = f[j] + 1;
                }
            }
        }
        if (max_len < f[i])
        {
            max_len = f[i];
        }
    }
    free(f);
    return numsSize - max_len;
}
*/