/* https://leetcode.cn/problems/letter-case-permutation/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

char** letterCasePermutation(char* s, int* returnSize);
void backtrack(char **ans, char *s, int len_s, int *returnSize, char *path, int top);

int main(void){
    char *s = "a1b2";
    int returnSize;
    char **ans = letterCasePermutation(s, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%s\n", ans[i]);
    }
    return 0;
}

char** letterCasePermutation(char* s, int* returnSize){
    int len_s = strlen(s);
    char **ans = malloc(sizeof(char *) * pow(2, len_s));
    char *path = malloc(sizeof(char) * (len_s + 1));
    *returnSize = 0;
    backtrack(ans, s, len_s, returnSize, path, 0);
    return ans;
}

void backtrack(char **ans, char *s, int len_s, int *returnSize, char *path, int top){
    if (*s == '\0')
    {
        ans[*returnSize] = malloc(sizeof(char) * (len_s + 1));
        memcpy(ans[*returnSize], path, sizeof(char) * top);
        ans[(*returnSize)++][len_s] = '\0';
    }
    else
    {
        if (isdigit(*s))
        {
            path[top] = *s;
            backtrack(ans, s + 1, len_s, returnSize, path, top + 1);
        }
        else
        {
            path[top] = *s;
            backtrack(ans, s + 1, len_s, returnSize, path, top + 1);
            path[top] = islower(*s) ? toupper(*s) : tolower(*s);
            backtrack(ans, s + 1, len_s, returnSize, path, top + 1);
        }
    }
}