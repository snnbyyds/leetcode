/* https://leetcode.cn/problems/climbing-stairs/ */

#include<stdio.h>
#include<stdlib.h>

int climbStairs(int n);
/*
int dfs(int n, int *cache);
*/

int main(void){
    int n = 3;
    printf("%d\n", climbStairs(n));
    return 0;
}

int climbStairs(int n){
    int f0 = 1;
    int f1 = 1;
    int new_f;
    for (int i = 2; i < n + 1; i++)
    {
        new_f = f0 + f1;
        f0 = f1;
        f1 = new_f;
    }
    return f1;
}

/*
int climbStairs(int n){
    int *cache = malloc(sizeof(int) * n);
    for (int i = 1; i <= n; i++)
    {
        cache[i - 1] = -1;
    }
    return dfs(n, cache);
}

int dfs(int n, int *cache){
    if (n <= 1)
    {
        return 1;
    }
    if (cache[n - 1] != -1)
    {
        return cache[n - 1];
    }
    int res = dfs(n - 1, cache) + dfs(n - 2, cache);
    cache[n - 1] = res;
    return res;
}
*/