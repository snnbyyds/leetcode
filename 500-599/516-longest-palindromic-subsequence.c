/* https://leetcode.cn/problems/longest-palindromic-subsequence/ */

#include<stdio.h>
#include<string.h>

int longestPalindromeSubseq(char* s);
// int dfs(char *s, int len_s, int cache[][len_s], int i, int j);
int max(int a, int b);

int main(void){
    char *s = "cbbd";
    printf("%d\n", longestPalindromeSubseq(s));
    return 0;
}

int longestPalindromeSubseq(char* s){
    int len_s = strlen(s);
    int f[len_s + 1][len_s + 1];
    memset(f, 0, sizeof(f));
    for (int i = len_s - 1; i >= 0; i--)
    {
        f[i][i] = 1;
        for (int j = i + 1; j < len_s; j++)
        {
            f[i][j] = s[i] == s[j] ? f[i + 1][j - 1] + 2 : max(f[i + 1][j], f[i][j - 1]);
        }
    }
    return f[0][len_s - 1];
}

int max(int a, int b){
    return a > b ? a : b;
}

/*
int longestPalindromeSubseq(char* s){
    int len_s = strlen(s);
    int cache[len_s][len_s];
    memset(cache, 0x80, sizeof(cache));
    return dfs(s, len_s, cache, 0, len_s - 1);
}

int dfs(char *s, int len_s, int cache[][len_s], int i, int j){
    if (i >= j)
    {
        return j - i + 1;
    }
    if (cache[i][j] != -2139062144)
    {
        return cache[i][j];
    }
    if (s[i] == s[j])
    {
        cache[i][j] = dfs(s, len_s, cache, i + 1, j - 1) + 2;
        return cache[i][j];
    }
    cache[i][j] = max(dfs(s, len_s, cache, i + 1, j), dfs(s, len_s, cache, i, j - 1));
    return cache[i][j];
}

int max(int a, int b){
    return a > b ? a : b;
}
*/