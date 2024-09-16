/* https://leetcode.cn/problems/interleaving-string/ */

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool isInterleave(char* s1, char* s2, char* s3);

int main(void){
    char *s1 = "aabcc", *s2 = "dbbca", *s3 = "aadbbcbcac";
    printf("%d\n", isInterleave(s1, s2, s3) ? 1 : 0);
    return 0;
}

bool isInterleave(char* s1, char* s2, char* s3){
    int len_1 = strlen(s1);
    int len_2 = strlen(s2);
    int len_3 = strlen(s3);
    if (len_3 != len_1 + len_2)
    {
        return false;
    }
    bool f[len_1 + 1][len_2 + 1];
    memset(f, 0, sizeof(f));
    f[0][0] = true;
    for (int j = 1; j <= len_2; j++)
    {
        f[0][j] = (f[0][j - 1] && s2[j - 1] == s3[j - 1]);
    }
    for (int i = 0; i < len_1; i++)
    {
        f[i + 1][0] = (f[i][0] && s1[i] == s3[i]);
        for (int j = 0; j < len_2; j++)
        {
            if (s1[i] == s3[i + j + 1] && s2[j] == s3[i + j + 1])
            {
                f[i + 1][j + 1] = f[i][j + 1] || f[i + 1][j];
                continue;
            }
            if (s1[i] == s3[i + j + 1])
            {
                f[i + 1][j + 1] = f[i][j + 1];
                continue;
            }
            if (s2[j] == s3[i + j + 1])
            {
                f[i + 1][j + 1] = f[i + 1][j];
                continue;
            }
            f[i + 1][j + 1] = false;
        }
    }
    return f[len_1][len_2];
}