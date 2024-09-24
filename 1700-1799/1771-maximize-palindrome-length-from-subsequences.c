/* https://leetcode.cn/problems/maximize-palindrome-length-from-subsequences/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int longestPalindrome(char* word1, char* word2);
int dfs(char *str, int str_len, int (*cache)[][str_len], int i, int j, int *ans, int len_1);
int max(int a, int b);

int main(void){
    char *word1 = "cacb", *word2 = "cbba";
    printf("%d\n", longestPalindrome(word1, word2));
    return 0;
}

int longestPalindrome(char* word1, char* word2){
    int len_1 = strlen(word1);
    int len_2 = strlen(word2);
    char *str = calloc(len_1 + len_2 + 1, sizeof(char));
    strcpy(str, word1);
    strcat(str, word2);
    int str_len = len_1 + len_2;
    int (*cache)[str_len][str_len] = malloc(sizeof(*cache));
    memset(*cache, 0x80, sizeof(*cache)); // -2139062144
    int ans = 0;
    dfs(str, str_len, cache, 0, str_len - 1, &ans, len_1);
    return ans;
}

int dfs(char *str, int str_len, int (*cache)[][str_len], int i, int j, int *ans, int len_1){
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        return 1;
    }
    if ((*cache)[i][j] != -2139062144)
    {
        return (*cache)[i][j];
    }
    int ret;
    if (str[i] == str[j])
    {
        ret = dfs(str, str_len, cache, i + 1, j - 1, ans, len_1) + 2;
        (*cache)[i][j] = ret;
        if (i < len_1 && j >= len_1 && *ans < ret)
        {
            *ans = ret;
        }
        return ret;
    }
    ret = max(dfs(str, str_len, cache, i + 1, j, ans, len_1), dfs(str, str_len, cache, i, j - 1, ans, len_1));
    (*cache)[i][j] = ret;
    return ret;
}

int max(int a, int b){
    return a > b ? a : b;
}