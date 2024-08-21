/* https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/ */

#include<stdio.h>
#include<stdlib.h>

int maximumTastiness(int* price, int priceSize, int k);
int cmp(const void *a, const void *b);
int f(int* price, int priceSize, int sweet);

int main(void){
    int price[6] = {13, 5, 1, 8, 21, 2};
    int k = 3;
    printf("%d\n", maximumTastiness(price, 6, k));
    return 0;
}

int maximumTastiness(int* price, int priceSize, int k){
    qsort(price, priceSize, sizeof(int), cmp);
    int left = 0;
    int right = (price[priceSize - 1] - price[0]) / (k - 1);
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (f(price, priceSize, mid) >= k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return right;
}

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int f(int* price, int priceSize, int sweet){
    int cnt = 1;
    int pre = price[0];
    for (int i = 1; i < priceSize; i++)
    {
        if (price[i] - pre >= sweet)
        {
            pre = price[i];
            cnt++;
        }
    }
    return cnt;
}