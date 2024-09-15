/* https://leetcode.cn/problems/longest-common-subsequence/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int longestCommonSubsequence(char* text1, char* text2);
// int dfs(char* text1, char* text2, int i, int j, int len_2, int cache[][len_2 + 1]);

int main(void){
    char *text1 = "abcde";
    char *text2 = "acef";
    printf("%d\n", longestCommonSubsequence(text1, text2));
    return 0;
}

int longestCommonSubsequence(char* text1, char* text2){
    int len_1 = strlen(text1);
    int len_2 = strlen(text2);
    int f[len_1 + 1][len_2 + 1];
    memset(f, 0, sizeof(f));
    f[0][0] = 0;
    for (int i = 0; i < len_1; i++)
    {
        for (int j = 0; j < len_2; j++)
        {
            f[i + 1][j + 1] = text1[i] == text2[j] ? f[i][j] + 1 : (f[i + 1][j] > f[i][j + 1] ? f[i + 1][j] : f[i][j + 1]);
        }
    }
    return f[len_1][len_2];
}

/*
int longestCommonSubsequence(char* text1, char* text2){
    int len_1 = strlen(text1);
    int len_2 = strlen(text2);
    int cache[len_1 + 1][len_2 + 1];
    memset(cache, -1, sizeof(cache));
    return dfs(text1, text2, len_1 - 1, len_2 - 1, len_2, cache);
}

int dfs(char* text1, char* text2, int i, int j, int len_2, int cache[][len_2 + 1]){
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (cache[i][j] != -1)
    {
        return cache[i][j];
    }
    if (text1[i] == text2[j])
    {
        cache[i][j] = dfs(text1, text2, i - 1, j - 1, len_2, cache) + 1;
        return cache[i][j];
    }
    int c1 = dfs(text1, text2, i - 1, j, len_2, cache);
    int c2 = dfs(text1, text2, i, j - 1, len_2, cache);
    cache[i][j] = c1 > c2 ? c1 : c2;
    return cache[i][j];
}
*/