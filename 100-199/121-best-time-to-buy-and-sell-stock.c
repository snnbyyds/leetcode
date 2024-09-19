/* https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/ */

#include<stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize);

int main(void){
    int prices[] = {7, 1, 5, 3, 6, 4};
    printf("%d\n", maxProfit(prices, sizeof(prices) / sizeof(int)));
    return 0;
}

int maxProfit(int* prices, int pricesSize) {
    int ans = 0;
    int min_price = 10001;
    for (int i = 0; i < pricesSize; i++) {
        int p = prices[i];
        ans = MAX(ans, p - min_price);
        min_price = MIN(min_price, p);
    }
    return ans;
}