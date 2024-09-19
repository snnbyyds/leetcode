/* https://leetcode.cn/problems/longest-palindromic-substring/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

char* longestPalindrome(char* s);
// int dfs(char *s, int len_s, int cache[][len_s], int i, int j, int *start, int *end);

int main(void){
    char *s = "aacabdkacaa";
    printf("%s\n", longestPalindrome(s));
    return 0;
}

//dp
char* longestPalindrome(char* s){
    int len_s = strlen(s);
    bool f[len_s][len_s];
    memset(f, 0, sizeof(f));
    int end = -1;
    int start = len_s + 1;
    for (int i = len_s - 1; i >= 0; i--)
    {
        for (int j = i; j < len_s; j++)
        {
            if (j == i)
            {
                f[i][j] = true;
            }
            else if (j - i <= 2)
            {
                f[i][j] = (s[i] == s[j]);
            }
            else if (j - i > 2)
            {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
            if (f[i][j] && end - start < j - i)
            {
                end = j;
                start = i;
            }
        }
    }
    if (end < start)
    {
        return "";
    }
    char *ans = malloc(sizeof(char) * (end - start + 2));
    strncpy(ans, s + start, end - start + 1);
    ans[end - start + 1] = '\0';
    return ans;
}

// a bad dfs solution

/*
char* longestPalindrome(char* s){
    int len_s = strlen(s);
    int cache[len_s][len_s];
    memset(cache, 0x80, sizeof(cache));
    int start = len_s + 1;
    int end = -1;
    dfs(s, len_s, cache, 0, len_s - 1, &start, &end);
    if (end < start)
    {
        return "";
    }
    char *ans = malloc(sizeof(char) * (end - start + 2));
    strncpy(ans, s + start, end - start + 1);
    ans[end - start + 1] = '\0';
    return ans;
}

int dfs(char *s, int len_s, int cache[][len_s], int i, int j, int *start, int *end){
    if (i == j || (i == j - 1 && s[i] == s[j]))
    {
        if (j - i > *end - *start)
        {
            *end = j;
            *start = i;
        }
        cache[i][j] = j - i + 1;
        return j - i + 1;
    }
    if (cache[i][j] > 0)
    {
        if (j - i > *end - *start)
        {
            *end = j;
            *start = i;
        }
        return cache[i][j];
    }
    if (s[i] == s[j])
    {
        cache[i][j] = dfs(s, len_s, cache, i + 1, j - 1, start, end) + 2;
        if (cache[i][j] > 0 && j - i > *end - *start)
        {
            *end = j;
            *start = i;
        }
        else if (cache[i][j] <= 0)
        {
            dfs(s, len_s, cache, i + 1, j, start, end);
            dfs(s, len_s, cache, i, j - 1, start, end);
        }
        return cache[i][j];
    }
    dfs(s, len_s, cache, i + 1, j, start, end);
    dfs(s, len_s, cache, i, j - 1, start, end);
    return cache[i][j];
}
*/
