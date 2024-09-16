/* https://leetcode.cn/problems/delete-operation-for-two-strings/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minDistance(char* word1, char* word2);

int main(void){
    char *word1 = "leetcode";
    char *word2 = "etco";
    printf("%d\n", minDistance(word1, word2));
    return 0;
}

int minDistance(char* word1, char* word2){
    int len_1 = strlen(word1);
    int len_2 = strlen(word2);
    int f[len_1 + 1][len_2 + 1];
    memset(f, 0, sizeof(f));
    for (int j = 1; j <= len_2; j++)
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
            f[i + 1][j + 1] = MIN(f[i + 1][j], f[i][j + 1]) + 1;
        }
    }
    return f[len_1][len_2];
}