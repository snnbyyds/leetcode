/* https://leetcode.cn/problems/count-ways-to-build-good-strings/ */

#include<stdio.h>
#include<stdlib.h>

int countGoodStrings(int low, int high, int zero, int one);
int func(int len, int zero, int one, int *f);

int main(void){
    int low = 2, high = 3, zero = 1, one = 2;
    printf("%d\n", countGoodStrings(low, high, zero, one));
    return 0;
}

int countGoodStrings(int low, int high, int zero, int one){
    int *f = malloc(sizeof(int) * (high + 1));
    int ans = func(high, zero, one, f) % 1000000007;
    for (int i = low; i < high; i++)
    {
        ans += f[i];
        ans %= 1000000007;
    }
    free(f);
    return ans;
}

int func(int len, int zero, int one, int *f){
    f[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        f[i] = ((i < zero ? 0 : f[i - zero]) + (i < one ? 0 : f[i - one])) % 1000000007;
    }
    return f[len];
}

/*
int countGoodStrings(int low, int high, int zero, int one);
int dfs(int len, int zero, int one, int *cache);

int main(void){
    int low = 2, high = 3, zero = 1, one = 2;
    printf("%d\n", countGoodStrings(low, high, zero, one));
    return 0;
}

int countGoodStrings(int low, int high, int zero, int one){
    int *cache = malloc(sizeof(int) * (high + 1));
    for (int i = 0; i < high + 1; i++)
    {
        cache[i] = -1;
    }
    int ans = 0;
    for (int i = low; i <= high; i++)
    {
        ans += dfs(i, zero, one, cache);
        ans %= 1000000007;
    }
    return ans;
}

int dfs(int len, int zero, int one, int *cache){
    if (len < 0)
    {
        return 0;
    }
    if (len == 0)
    {
        return 1;
    }
    if (cache[len] != -1)
    {
        return cache[len];
    }
    int res = (dfs(len - zero, zero, one, cache) % 1000000007 + dfs(len - one, zero, one, cache) % 1000000007) % 1000000007;
    cache[len] = res;
    return res;
}
*/