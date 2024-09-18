/* https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/ */

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int maxProfit(int k, int* prices, int pricesSize);
int dfs(int k, int *prices, int i, bool hold, int remain, int cache[][2][k * 2 + 1]);
int max(int a, int b);

int main(void){
    int k = 2;
    int prices[] = {2, 4, 1};
    printf("%d\n", maxProfit(k, prices, sizeof(prices) / sizeof(int)));
    return 0;
}

int maxProfit(int k, int* prices, int pricesSize){
    int cache[pricesSize][2][k * 2 + 1];
    memset(cache, 0x80, sizeof(cache));
    return dfs(k, prices, pricesSize - 1, false, k * 2, cache);
}

int dfs(int k, int *prices, int i, bool hold, int remain, int cache[][2][k * 2 + 1]){
    if (i < 0)
    {
        return hold ? -2139062144 : 0;
    }
    if (cache[i][hold][remain] != -2139062144)
    {
        return cache[i][hold][remain];
    }
    if (remain > 0)
    {
        cache[i][hold][remain] = hold ? max(dfs(k, prices, i - 1, true, remain, cache), dfs(k, prices, i - 1, false, remain - 1, cache) - prices[i]) : max(dfs(k, prices, i - 1, false, remain, cache), dfs(k, prices, i - 1, true, remain - 1, cache) + prices[i]);
        return cache[i][hold][remain];
    }
    cache[i][hold][remain] = dfs(k, prices, i - 1, hold, remain, cache);
    return cache[i][hold][remain];
}

int max(int a, int b){
    return a > b ? a : b;
}