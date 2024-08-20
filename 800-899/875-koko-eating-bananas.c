/* https://leetcode.cn/problems/koko-eating-bananas/ */

#include<stdio.h>
#include<math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minEatingSpeed(int* piles, int pilesSize, int h);
int maxinpiles(int* piles, int pilesSize);
long long gettime(int* piles, int pilesSize, int k);

int main(void){
    int piles[4] = {3, 6, 7, 11};
    int h = 8;
    printf("%d\n", minEatingSpeed(piles, 4, h));
    return 0;
}

int minEatingSpeed(int* piles, int pilesSize, int h){
    int mid;
    int left = 1;
    int right = maxinpiles(piles, pilesSize);
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (gettime(piles, pilesSize, mid) > h)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}

int maxinpiles(int* piles, int pilesSize){
    int max = piles[0];
    for (int i = 1; i < pilesSize; i++)
    {
        max = MAX(max, piles[i]);
    }
    return max;
}

long long gettime(int* piles, int pilesSize, int k){
    long long t = 0;
    for (int i = 0; i < pilesSize; i++)
    {
        t += (long long)ceil((double)piles[i] / k);
    }
    return t;
}