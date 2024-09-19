/* https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize);

int main(void){
    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    printf("%d\n", maxProfit(prices, sizeof(prices) / sizeof(int)));
    return 0;
}

int maxProfit(int* prices, int pricesSize){
    int f[pricesSize + 1][2][6]; // f[i + 1][hold][remain]
    memset(f[0][0], 0, sizeof(f));
    memset(f[0][1], 0x80, sizeof(int) * 5);
    for (int i = 0; i < pricesSize; i++)
    {
        f[i + 1][1][0] = f[i][1][0];
        f[i + 1][0][0] = f[i][0][0];
        for (int remain = 0; remain <= 4; remain++)
        {
            f[i + 1][0][remain + 1] = MAX(f[i][0][remain + 1], f[i][1][remain] + prices[i]);
            f[i + 1][1][remain + 1] = MAX(f[i][1][remain + 1], f[i][0][remain] - prices[i]);
        }
    }
    return f[pricesSize][0][5];
}