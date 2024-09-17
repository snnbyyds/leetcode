/* https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int maxProfit(int* prices, int pricesSize);
int dfs(int *prices, int cache[][2], int i, bool hold);
int max(int a, int b);

int main(void){
    int prices[] = {1, 2, 3, 0, 2};
    printf("%d\n", maxProfit(prices, sizeof(prices) / sizeof(int)));
    return 0;
}

int maxProfit(int* prices, int pricesSize){
    int cache[pricesSize][2];
    memset(cache, 0x80, sizeof(cache));
    return dfs(prices, cache, pricesSize - 1, false);
}

int dfs(int *prices, int cache[][2], int i, bool hold){
    if (i < 0)
    {
        return hold ? -2139062144 : 0;
    }
    if (cache[i][hold] != -2139062144)
    {
        return cache[i][hold];
    }
    cache[i][hold] = hold ? max(dfs(prices, cache, i - 1, true), dfs(prices, cache, i - 2, false) - prices[i]) : max(dfs(prices, cache, i - 1, false), dfs(prices, cache, i - 1, true) + prices[i]);
    return cache[i][hold];
}

int max(int a, int b){
    return a > b ? a : b;
}