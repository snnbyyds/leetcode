/* https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int minInsertions(char* s);
// int dfs(char *s, int len_s, int (*cache)[][len_s], int left, int right);
int min(int a, int b);

int main(void){
    char *s = "leetcode";
    printf("%d\n", minInsertions(s));
    return 0;
}

int minInsertions(char* s){
    int len_s = strlen(s);
    int (*f)[len_s + 1][len_s + 1] = calloc((len_s + 1) * (len_s + 1), sizeof(int));
    for (int left = len_s - 1; left >= 0; left--)
    {
        for (int right = left + 1; right < len_s; right++)
        {
            (*f)[left][right + 1] = s[left] == s[right] ? (*f)[left + 1][right] : min((*f)[left + 1][right + 1] + 1, (*f)[left][right] + 1);
        }
    }
    int ret = (*f)[0][len_s];
    free(f);
    return ret;
}

int min(int a, int b){
    return a < b ? a : b;
}

/*
int minInsertions(char* s){
    int len_s = strlen(s);
    int (*cache)[len_s][len_s] = malloc(sizeof(*cache));
    memset(*cache, 0x80, sizeof(*cache)); // -2139062144
    int ret = dfs(s, len_s, cache, 0, len_s - 1);
    free(cache);
    return ret;
}

int dfs(char *s, int len_s, int (*cache)[][len_s], int left, int right){
    if (left >= right)
    {
        return 0;
    }
    if ((*cache)[left][right] != -2139062144)
    {
        return (*cache)[left][right];
    }
    int ret = s[left] == s[right] ? dfs(s, len_s, cache, left + 1, right - 1) : min(dfs(s, len_s, cache, left + 1, right) + 1, dfs(s, len_s, cache, left, right - 1) + 1);
    (*cache)[left][right] = ret;
    return ret;
}

int min(int a, int b){
    return a < b ? a : b;
}
*/