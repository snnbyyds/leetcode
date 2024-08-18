/* https://leetcode.cn/problems/container-with-most-water/ */

#include<stdio.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int ans = 0;
    int s;
    while (left < right) {
        s = (right - left) * MIN(height[left], height[right]);
        ans = MAX(ans, s);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return ans; 
}

int main(void) {
    int height[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("%d\n", maxArea(height, 9));
    return 0;
}