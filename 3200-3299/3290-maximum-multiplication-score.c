/* https://leetcode.cn/problems/maximum-multiplication-score/ */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long maxScore(int* a, int aSize, int* b, int bSize);
// long long dfs(int *a, int *b, int i, int j, long long cache[][4]);

int main(void){
    int a[4] = {3, 2, 5, 6};
    int b[7] = {2, -6, 4, -5, -3, 2, -7};
    printf("%lld\n", maxScore(a, 4, b, 7));
    return 0;
}

// dp
// f[i + 1][j + 1] = max{f[i][j + 1], f[i][j] + a[j] * b[i]}

long long maxScore(int* a, int aSize, int* b, int bSize){
    long long f[100002][5];
    memset(f, 0, sizeof(f));
    for (int i = 1; i < 5; i++)
    {
        f[0][i] = LLONG_MIN / 7 * 6;
    }
    for (int i = 0; i < bSize; i++)
    {
        for (int j = 0; j < aSize; j++)
        {
            f[i + 1][j + 1] = MAX(f[i][j + 1], f[i][j] + (long long)a[j] * (long long)b[i]);
        }
    }
    return f[bSize][aSize];
}

// dfs

/*
long long maxScore(int* a, int aSize, int* b, int bSize){
    long long cache[100000][4];
    memset(cache, 0, sizeof(cache));
    long long res = dfs(a, b, bSize - 1, aSize - 1, cache);
    return res == LLONG_MIN ? -1 : res;
}

// dfs(i, j) = max{dfs(i - 1, j), dfs(i - 1, j - 1) + a[j] * b[i]}
// i is idx in b ans j is idx in a
long long dfs(int *a, int *b, int i, int j, long long cache[][4]){
    if (j == -1)
    {
        return 0;
    }
    if (i == -1 && j >= 0)
    {
        return LLONG_MIN;
    }
    if (cache[i][j] != 0)
    {
        return cache[i][j];
    }
    long long c1 = dfs(a, b, i - 1, j, cache);
    long long c2 = dfs(a, b, i - 1, j - 1, cache);
    c2 = c2 != LLONG_MIN ? c2 + (long long)a[j] * (long long)b[i] : LLONG_MIN;
    cache[i][j] = c1 > c2 ? c1 : c2;
    return cache[i][j];
}
*/

// backtrack

/*
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void backtrack(long long *ans, int* a, int aSize, int* b, int bSize, int *path, int top, int startidx){
    if (top == 4)
    {
        long long cur_ans = 0;
        for (int i = 0; i < top; i++)
        {
            cur_ans += a[i] * b[path[i]];
        }
        *ans = MAX(*ans, cur_ans);
        return;
    }
    for (int i = 0; i < bSize; i++)
    {
        if (top >= 1 && i <= path[top - 1])
        {
            continue;
        }
        if (top >= 1 && aSize - top > bSize - path[top - 1])
        {
            continue;
        }
        path[top] = i;
        backtrack(ans, a, aSize, b, bSize, path, top + 1, i + 1);
    }
}

long long maxScore(int* a, int aSize, int* b, int bSize){
    long long ans = LLONG_MIN;
    int *path = malloc(sizeof(int) * bSize);
    backtrack(&ans, a, aSize, b, bSize, path, 0, 0);
    return ans;
}
*/