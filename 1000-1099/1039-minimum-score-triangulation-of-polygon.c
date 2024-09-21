/* https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int minScoreTriangulation(int* values, int valuesSize);
// int dfs(int *values, int valuesSize, int (*cache)[][valuesSize], int i, int j);
int min(int a, int b);

int main(void){
    int values[] = {1, 3, 1, 4, 1, 5};
    printf("%d\n", minScoreTriangulation(values, sizeof(values) / sizeof(int)));
    return 0;
}

int minScoreTriangulation(int* values, int valuesSize){
    int (*f)[valuesSize][valuesSize] = malloc(sizeof(*f));
    memset(*f, 0, sizeof(*f));
    int cur;
    for (int i = valuesSize - 3; i >= 0; i--)
    {
        for (int j = i + 2; j < valuesSize; j++)
        {
            cur = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                cur = min((*f)[i][k] + (*f)[k][j] + values[i] * values[j] * values[k], cur);
            }
            (*f)[i][j] = cur;
        }
    }
    int ans = (*f)[0][valuesSize - 1];
    free(f);
    return ans;
}

int min(int a, int b){
    return a < b ? a : b;
}

/*
int minScoreTriangulation(int* values, int valuesSize){
    int (*cache)[valuesSize][valuesSize] = malloc(sizeof(int) * valuesSize * valuesSize);
    memset(*cache, 0x80, sizeof(*cache)); // -2139062144
    int ans = dfs(values, valuesSize, cache, 0, valuesSize - 1);
    free(cache);
    return ans;
}

// dfs(i, j) = min{dfs(i, k) + dfs(j, k) + values[i] * values[j] * values[k], ...}
int dfs(int *values, int valuesSize, int (*cache)[][valuesSize], int i, int j){
    if (j == i + 1)
    {
        return 0; // dfs(i, i + 1) = 0;
    }
    if ((*cache)[i][j] != -2139062144)
    {
        return (*cache)[i][j];
    }
    int res = INT_MAX >> 1;
    for (int k = i + 1; k < j; k++)
    {
        res = min(res, dfs(values, valuesSize, cache, i, k) + dfs(values, valuesSize, cache, k, j) + values[i] * values[j] * values[k]);
    }
    (*cache)[i][j] = res;
    return res;
}

int min(int a, int b){
    return a < b ? a : b;
}
*/