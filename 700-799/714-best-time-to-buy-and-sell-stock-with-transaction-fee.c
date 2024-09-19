/* https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int maxProfit(int* prices, int pricesSize, int fee);
// int dfs(int *prices, int fee, int cache[][2], int i, bool hold);
int max(int a, int b);

int main(void){
    int prices[] = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    printf("%d\n", maxProfit(prices, sizeof(prices) / sizeof(int), fee));
    return 0;
}

// dp
int maxProfit(int* prices, int pricesSize, int fee){
    int f[pricesSize + 1][2];
    f[0][0] = 0;
    f[0][1] = -2139062144;
    for (int i = 0; i < pricesSize; i++)
    {
        f[i + 1][1] = max(f[i][1], f[i][0] - prices[i]);
        f[i + 1][0] = max(f[i][0], f[i][1] + prices[i] - fee);
    }
    return f[pricesSize][0];
}

int max(int a, int b){
    return a > b ? a : b;
}


// dfs
/*
int maxProfit(int* prices, int pricesSize, int fee){
    int cache[pricesSize][2];
    memset(cache, 0x80, sizeof(cache));
    return dfs(prices, fee, cache, pricesSize - 1, false);
}

int dfs(int *prices, int fee, int cache[][2], int i, bool hold){
    if (i < 0)
    {
        return hold ? -2139062144 : 0;
    }
    if (cache[i][hold] != -2139062144)
    {
        return cache[i][hold];
    }
    if (hold)
    {
        cache[i][hold] = max(dfs(prices, fee, cache, i - 1, true), dfs(prices, fee, cache, i - 1, false) - prices[i]);
        return cache[i][hold];
    }
    cache[i][hold] = prices[i] <= fee ? dfs(prices, fee, cache, i - 1, false) : max(dfs(prices, fee, cache, i - 1, false), dfs(prices, fee, cache, i - 1, true) + prices[i] - fee);
    return cache[i][hold];
}

int max(int a, int b){
    return a > b ? a : b;
}
*/