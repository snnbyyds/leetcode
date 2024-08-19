/* https://leetcode.cn/problems/max-consecutive-ones-iii/ */

#include<stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestOnes(int* nums, int numsSize, int k);

int main(void){
    int nums[19] = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    printf("%d\n", longestOnes(nums, 19, k));
    return 0;
}

int longestOnes(int* nums, int numsSize, int k){
    int ans = 0;
    int left = 0;
    int flip = 0;
    for (int right = 0; right < numsSize; right++)
    {
        flip += (nums[right] == 0);
        while (flip > k)
        {
            flip -= (nums[left] == 0);
            left++;
        }
        ans = MAX(ans, right - left + 1);
    }
    return ans;
}