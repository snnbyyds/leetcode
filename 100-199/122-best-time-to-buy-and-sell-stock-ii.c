/* https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize);
// int dfs(int *prices, int i, bool hold, int cache[][2]);
// int max(int a, int b);

int main(void){
    int prices[] = {7, 1, 5, 3, 6, 4};
    printf("%d\n", maxProfit(prices, sizeof(prices) / sizeof(int)));
    return 0;
}

// dp
int maxProfit(int* prices, int pricesSize){
    int f[pricesSize + 1][2];
    f[0][1] = -2139062144;
    f[0][0] = 0;
    for (int i = 0; i < pricesSize; i++)
    {
        f[i + 1][0] = MAX(f[i][0], f[i][1] + prices[i]);
        f[i + 1][1] = MAX(f[i][1], f[i][0] - prices[i]);
    }
    return f[pricesSize][0];
}

// dfs
/*
int maxProfit(int* prices, int pricesSize){
    int cache[pricesSize][2];
    memset(cache, 0x80, sizeof(cache)); // -2139062144
    return dfs(prices, pricesSize - 1, false, cache);
}

int dfs(int *prices, int i, bool hold, int cache[][2]){
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
        cache[i][true] = max(dfs(prices, i - 1, true, cache), dfs(prices, i - 1, false, cache) - prices[i]);
        return cache[i][true];
    }
    cache[i][false] = max(dfs(prices, i - 1, false, cache), dfs(prices, i - 1, true, cache) + prices[i]);
    return cache[i][false];
}

int max(int a, int b){
    return a > b ? a : b;
}
*/