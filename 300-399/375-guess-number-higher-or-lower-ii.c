/* https://leetcode.cn/problems/guess-number-higher-or-lower-ii/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int getMoneyAmount(int n);
int dfs(int n, int (*cache)[][n + 1], int i, int j);
int max(int a, int b);
int min(int a, int b);

int main(void){
    int n = 10;
    printf("%d\n", getMoneyAmount(n));
    return 0;
}

int getMoneyAmount(int n){
    int (*cache)[n + 1][n + 1] = malloc(sizeof(*cache));
    memset(*cache, 0x80, sizeof(*cache));
    int ans = dfs(n, cache, 1, n);
    free(cache);
    return ans;
}

int dfs(int n, int (*cache)[][n + 1], int i, int j){
    if (i >= j)
    {
        return 0;
    }
    if ((*cache)[i][j] != -2139062144)
    {
        return (*cache)[i][j];
    }
    int cur = INT_MAX;
    for (int k = i; k <= j; k++)
    {
        cur = min(cur, k + max(dfs(n, cache, i, k - 1), dfs(n, cache, k + 1, j)));
    }
    (*cache)[i][j] = cur;
    return cur;
}

int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}