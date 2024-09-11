/* https://leetcode.cn/problems/n-queens/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes);
void backtrack(char ***ans, int n, int* returnSize, int** returnColumnSizes, int *path, int top, bool *map, bool *map_sum, bool *map_delta);

int main(void){
    int n = 4;
    int returnSize;
    int *returnColumnSizes;
    char ***ans = solveNQueens(n, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            for (int k = 0; k < strlen(ans[i][j]); k++)
            {
                printf("%c\t", ans[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    char ***ans = malloc(sizeof(char**) * 352);
    *returnColumnSizes = malloc(sizeof(int) * 352);
    int *path = malloc(sizeof(int) * n); // contains selected c
    bool *map = calloc(n, sizeof(bool)); // maps selected c
    bool *map_sum = calloc(n * 2, sizeof(bool)); // maps r + c
    bool *map_delta = calloc(n * 2 - 1, sizeof(bool)); // maps r - c
    backtrack(ans, n, returnSize, returnColumnSizes, path, 0, map, map_sum, map_delta);
    return ans;
}

void backtrack(char ***ans, int n, int* returnSize, int** returnColumnSizes, int *path, int top, bool *map, bool *map_sum, bool *map_delta){
    if (top == n)
    {
        ans[*returnSize] = malloc(sizeof(char*) * n);
        for (int i = 0; i < n; i++)
        {
            ans[*returnSize][i] = malloc(sizeof(char) * (n + 1));
            ans[*returnSize][i][n] = '\0';
            memset(ans[*returnSize][i], '.', sizeof(char) * n);
            ans[*returnSize][i][path[i]] = 'Q';
        }
        (*returnColumnSizes)[(*returnSize)++] = n;
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
        backtrack(ans, n, returnSize, returnColumnSizes, path, top + 1, map, map_sum, map_delta);
        map[i] = false;
        map_sum[top + i] = false;
        map_delta[top - i + n - 1] = false;
    }
}