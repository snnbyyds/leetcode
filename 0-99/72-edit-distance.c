/* https://leetcode.cn/problems/edit-distance/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minDistance(char* word1, char* word2);
// int dfs(char* word1, char* word2, int len_2, int cache[][len_2 + 1], int i, int j);

int main(void){
    char *word1 = "intention";
    char *word2 = "execution";
    printf("%d\n", minDistance(word1, word2));
    return 0;
}

int minDistance(char* word1, char* word2){
    int len_1 = strlen(word1);
    int len_2 = strlen(word2);
    int f[len_1 + 1][len_2 + 1];
    memset(f, 0, sizeof(f));
    for (int j = 0; j <= len_2; j++)
    {
        f[0][j] = j;
    }
    for (int i = 0; i < len_1; i++)
    {
        f[i + 1][0] = i + 1;
        for (int j = 0; j < len_2; j++)
        {
            if (word1[i] == word2[j])
            {
                f[i + 1][j + 1] = f[i][j];
                continue;
            }
            f[i + 1][j + 1] = MIN(f[i][j], MIN(f[i + 1][j], f[i][j + 1])) + 1;
        }
    }
    return f[len_1][len_2];
}

/*
int minDistance(char* word1, char* word2){
    int len_1 = strlen(word1);
    int len_2 = strlen(word2);
    int cache[len_1 + 1][len_2 + 1];
    memset(cache, -1, sizeof(cache));
    return dfs(word1, word2, len_2, cache, len_1 - 1, len_2 - 1);
}

int dfs(char* word1, char* word2, int len_2, int cache[][len_2 + 1], int i, int j){
    if (i < 0)
    {
        return j + 1;
    }
    if (j < 0)
    {
        return i + 1;
    }
    if (cache[i][j] != -1)
    {
        return cache[i][j];
    }
    if (word1[i] == word2[j])
    {
        return dfs(word1, word2, len_2, cache, i - 1, j - 1);
    }
    int c[3] = {dfs(word1, word2, len_2, cache, i - 1, j - 1), dfs(word1, word2, len_2, cache, i - 1, j), dfs(word1, word2, len_2, cache, i, j - 1)};
    int res = INT_MAX;
    for (int i = 0; i < 3; i++)
    {
        if (res > c[i])
        {
            res = c[i];
        }
    }
    cache[i][j] = ++res;
    return res;
}
*/