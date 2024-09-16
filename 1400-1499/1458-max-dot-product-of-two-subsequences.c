/* https://leetcode.cn/problems/max-dot-product-of-two-subsequences/ */

#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size);
int dfs(int *nums1, int *nums2, int nums2Size, int i, int j, int cache[][nums2Size + 1]);
int max3(int a, int b, int c);

int main(void){
    int nums1[] = {-1, -1};
    int nums2[] = {1, 1};
    printf("%d\n", maxDotProduct(nums1, sizeof(nums1) / sizeof(int), nums2, sizeof(nums2) / sizeof(int)));
    return 0;
}

int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int cache[nums1Size + 1][nums2Size + 1];
    memset(cache, 0x80, sizeof(cache)); // -2139062144
    return dfs(nums1, nums2, nums2Size, nums1Size - 1, nums2Size - 1, cache);
}

int dfs(int *nums1, int *nums2, int nums2Size, int i, int j, int cache[][nums2Size + 1]){
    if (i < 0 || j < 0)
    {
        return -2139062144;
    }
    if (cache[i][j] != -2139062144)
    {
        return cache[i][j];
    }
    cache[i][j] = max3((int)fmax(dfs(nums1, nums2, nums2Size, i - 1, j - 1, cache), 0) + nums1[i] * nums2[j], dfs(nums1, nums2, nums2Size, i, j - 1, cache), dfs(nums1, nums2, nums2Size, i - 1, j, cache));
    return cache[i][j];
}

int max3(int a, int b, int c){
    int m = a;
    if (b > m)
    {
        m = b;
    }
    if (c > m)
    {
        m = c;
    }
    return m;
}