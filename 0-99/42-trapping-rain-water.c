/* https://leetcode.cn/problems/trapping-rain-water/ */

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int trap(int* height, int heightSize) {
    if(heightSize == 2) {
        return 0;
    }

    int maxpre[heightSize];
    maxpre[0] = height[0];
    for (int i = 1; i < heightSize; i++) {
        maxpre[i] = MAX(height[i], maxpre[i - 1]);
    }

    int maxsuf[heightSize];
    maxsuf[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 2; i >= 0; i--) {
        maxsuf[i] = MAX(height[i], maxsuf[i + 1]);
    }

    int v = 0;
    int v0;
    for (int i = 0; i < heightSize; i++) {
        v0 = MIN(maxpre[i], maxsuf[i]) - height[i];
        v += v0;
    }
    return v;
}

int main(void) {
    int height[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    printf("%d\n", trap(height, 12));
    return 0;
}