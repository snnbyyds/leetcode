/* https://leetcode.cn/problems/letter-combinations-of-a-phone-number/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char** letterCombinations(char* digits, int* returnSize);
void backtrack(char *digits, int *returnSize, char **ans, int idx, char *stack, int top, char **board);

int main(void){
    int returnSize;
    char *digits = "23";
    char **ans = letterCombinations(digits, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%s\n", ans[i]);
    }
    return 0;
}

char** letterCombinations(char* digits, int* returnSize){
    *returnSize = 0;
    int digitsLen = strlen(digits);
    if (digitsLen == 0)
    {
        return NULL;
    }
    char *two = "abc";
    char *three = "def";
    char *four = "ghi";
    char *five = "jkl";
    char *six = "mno";
    char *seven = "pqrs";
    char *eight = "tuv";
    char *nine = "wxyz";
    char *board[8] = {two, three, four, five, six, seven, eight, nine};
    char **ans = calloc(sizeof(char *), 144);
    // memset(ans, 0, 144 * sizeof(char *));
    char *pword = board[digits[0] - '2'];
    int idxLen = strlen(pword);
    char stack[4] = {0};
    for (int i = 0; i < idxLen; i++)
    {
        stack[0] = pword[i];
        backtrack(digits, returnSize, ans, 1, stack, 1, board);
    }
    return ans;
}

void backtrack(char *digits, int *returnSize, char **ans, int idx, char *stack, int top, char **board){
    int len = strlen(digits);
    if (top >= len)
    {
        ans[*returnSize] = malloc(sizeof(char) * (top + 1));
        memcpy(ans[*returnSize], stack, sizeof(char) * top);
        ans[(*returnSize)++][top] = '\0';
    }
    else
    {
        char *pword = board[digits[idx] - '2'];
        int idxLen = strlen(pword);
        for (int i = 0; i < idxLen; i++)
        {
            stack[top] = pword[i];
            backtrack(digits, returnSize, ans, idx + 1, stack, top + 1, board);
        }
    }
}