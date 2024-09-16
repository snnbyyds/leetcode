/* https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/ */

#include<stdio.h>
#include<string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumDeleteSum(char* s1, char* s2);

int main(void){
    char *s1 = "delete";
    char *s2 = "leet";
    printf("%d\n", minimumDeleteSum(s1, s2));
    return 0;
}

int minimumDeleteSum(char* s1, char* s2){
    int len_1 = strlen(s1);
    int len_2 = strlen(s2);
    int f[len_1 + 1][len_2 + 1];
    memset(f, 0, sizeof(f));
    f[0][0] = 0;
    for (int j = 1; j <= len_2; j++)
    {
        f[0][j] = f[0][j - 1] + s2[j - 1];
    }
    for (int i = 0; i < len_1; i++)
    {
        f[i + 1][0] = f[i][0] + s1[i];
        for (int j = 0; j < len_2; j++)
        {
            if (s1[i] == s2[j])
            {
                f[i + 1][j + 1] = f[i][j];
                continue;
            }
            f[i + 1][j + 1] = MIN(f[i + 1][j] + s2[j], f[i][j + 1] + s1[i]);
        }
    }
    return f[len_1][len_2];
}