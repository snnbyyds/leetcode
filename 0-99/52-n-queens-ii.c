/* https://leetcode.cn/problems/n-queens-ii/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int totalNQueens(int n);
void backtrack(int *ans, int n, int *path, int top, bool *map, bool *map_sum, bool *map_delta);

int main(void){
    int n = 4;
    printf("%d\n", totalNQueens(n));
    return 0;
}

int totalNQueens(int n){
    int ans = 0;
    int *path = malloc(sizeof(int) * n); // contains selected c
    bool *map = calloc(n, sizeof(bool)); // maps selected c
    bool *map_sum = calloc(n * 2, sizeof(bool)); // maps r + c
    bool *map_delta = calloc(n * 2 - 1, sizeof(bool)); // maps r - c
    backtrack(&ans, n, path, 0, map, map_sum, map_delta);
    return ans;
}

void backtrack(int *ans, int n, int *path, int top, bool *map, bool *map_sum, bool *map_delta){
    if (top == n)
    {
        (*ans)++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (map[i] || map_sum[top + i] || map_delta[top - i + n - 1])
        {
            continue;
        }
        path[top] = i;
        map[i] = true;
        map_sum[top + i] = true;
        map_delta[top - i + n - 1] = true;
        backtrack(ans, n, path, top + 1, map, map_sum, map_delta);
        map[i] = false;
        map_sum[top + i] = false;
        map_delta[top - i + n - 1] = false;
    }
}