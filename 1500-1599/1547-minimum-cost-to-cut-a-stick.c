/* https://leetcode.cn/problems/minimum-cost-to-cut-a-stick/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int minCost(int n, int* cuts, int cutsSize);
int dfs(int n, int *cuts, int cutsSize, int (*cache)[][cutsSize + 2], int i, int j);
int cmp(const void *a, const void *b);
int min(int a, int b);

int main(void){
    int cuts[5] = {5, 6, 1, 4, 2};
    int n = 9;
    printf("%d\n", minCost(n, cuts, 5));
    return 0;
}

int minCost(int n, int* cuts, int cutsSize){
    qsort(cuts, cutsSize, sizeof(int), cmp);
    int (*cache)[cutsSize + 2][cutsSize + 2] = malloc(sizeof(*cache));
    memset(*cache, 0x80, sizeof(*cache));
    int ret = dfs(n, cuts, cutsSize, cache, -1, cutsSize);
    free(cache);
    return ret;
}

int dfs(int n, int *cuts, int cutsSize, int (*cache)[][cutsSize + 2], int i, int j){
    if (i + 1 == j || i == j)
    {
        return 0;
    }
    if ((*cache)[i + 1][j + 1] != -2139062144)
    {
        return (*cache)[i + 1][j + 1];
    }
    int ret = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ret = min(ret, dfs(n, cuts, cutsSize, cache, i, k) + dfs(n, cuts, cutsSize, cache, k, j) + (j == cutsSize ? n : cuts[j]) - (i == -1 ? 0 : cuts[i]));
    }
    (*cache)[i + 1][j + 1] = ret;
    return ret;
}

int min(int a, int b){
    return a < b ? a : b;
}

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}