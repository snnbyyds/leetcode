/* https://leetcode.cn/problems/generate-parentheses/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char** generateParenthesis(int n, int* returnSize);
void backtrack(char **ans, int n, int *returnSize, char *path, int top, int cnt_left);

int main(void){
    int returnSize;
    int n = 3;
    char **ans = generateParenthesis(n, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%s\n", ans[i]);
    }
    free(ans);
    return 0;
}

char** generateParenthesis(int n, int* returnSize){
    *returnSize = 0;
    char **ans = malloc(sizeof(char *) * 1430); // Catalan number
    char *path = malloc(sizeof(char) * (n * 2 + 1));
    backtrack(ans, n, returnSize, path, 0, 0);
    return ans;
}

void backtrack(char **ans, int n, int *returnSize, char *path, int top, int cnt_left){
    if (top == n * 2)
    {
        path[top++] = '\0';
        ans[*returnSize] = malloc(sizeof(char) * top);
        strcpy(ans[(*returnSize)++], path);
    }
    int cnt_right = top - cnt_left;
    if (cnt_left < n)
    {
        path[top] = '(';
        backtrack(ans, n, returnSize, path, top + 1, cnt_left + 1);
    }
    if (cnt_right < cnt_left)
    {
        path[top] = ')';
        backtrack(ans, n, returnSize, path, top + 1, cnt_left);
    }
}