/* https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int punishmentNumber(int n);
void backtrack(int *ans, char *str, char **path, int top, int startidx, int i, bool *map);
bool valid(char **path, int top, int i);

int main(void){
    int n = 91;
    printf("%d\n", punishmentNumber(n));
    return 0;
}

int punishmentNumber(int n){
    int ans = 0;
    char str[10];
    char **path = malloc(sizeof(char*) * 8);
    bool *map = calloc(n + 1, sizeof(bool)); // maps valid i
    for (int i = 1; i <= n; i++)
    {
        memset(str, '\0', sizeof(char) * 10);
        sprintf(str, "%d", i * i);
        backtrack(&ans, str, path, 0, 0, i, map);
    }
    return ans;
}

void backtrack(int *ans, char *str, char **path, int top, int startidx, int i, bool *map){
    if (*str == '\0')
    {
        if (valid(path, top, i) && !map[i])
        {
            map[i] = true;
            *ans += i * i;
        }
        return;
    }
    for (int j = 0; j < strlen(str); j++)
    {
        path[top] = malloc(sizeof(char) * (j + 2));
        strncpy(path[top], str, j + 1);
        path[top][j + 1] = '\0';
        backtrack(ans, str + j + 1, path, top + 1, j + 1, i, map);
    }
}

bool valid(char **path, int top, int i){
    int sum = 0;
    for (int j = 0; j < top; j++)
    {
        sum += atoi(path[j]);
    }
    return sum == i;
}