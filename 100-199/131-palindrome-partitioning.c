/* https://leetcode.cn/problems/palindrome-partitioning/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

char*** partition(char* s, int* returnSize, int** returnColumnSizes);
void backtrack(char ***ans, char *s, int len, int* returnSize, int** returnColumnSizes, char path[][len + 1], int idx);
bool ispalindrome(char* s, int left, int right);

int main(void){
    char *s = "aab";
    int returnSize;
    int *returnColumnSizes;
    char*** ans = partition(s, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%s\t", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes){
    int len_s = strlen(s);
    *returnSize = 0;
    char ***ans = malloc(sizeof(char**) * 65536);
    char path[len_s][len_s + 1];
    *returnColumnSizes = malloc(sizeof(int) * 65536);
    backtrack(ans, s, len_s, returnSize, returnColumnSizes, path, 0);
    return ans;
}

void backtrack(char ***ans, char *s, int len, int* returnSize, int** returnColumnSizes, char path[][len + 1], int idx){
    if (*s == '\0')
    {
        ans[*returnSize] = malloc(sizeof(char*) * len);
        for (int i = 0; i < idx; i++)
        {
            ans[*returnSize][i] = malloc(sizeof(char) * (len + 1));
            strcpy(ans[*returnSize][i], path[i]);
        }
        (*returnColumnSizes)[(*returnSize)++] = idx;
        return;
    }
    int len_s = strlen(s);
    for (int i = 0; i < len_s; i++)
    {
        if (ispalindrome(s, 0, i))
        {
            strncpy(path[idx], s, i + 1);
            path[idx][i + 1] = '\0';
            backtrack(ans, s + i + 1, len, returnSize, returnColumnSizes, path, idx + 1);
        }
    }
}

bool ispalindrome(char* s, int left, int right){
    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}