/* https://leetcode.cn/problems/count-number-of-texts/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int countTexts(char* pressedKeys);
int func(char *pressedKeys, int start, int len, int *f, char **board);

int main(void){
    char *pressedKeys = "22233";
    printf("%d\n", countTexts(pressedKeys));
    return 0;
}

int countTexts(char* pressedKeys){
    char *zero = "";
    char *one = "";
    char *two = "abc";
    char *three = "def";
    char *four = "ghi";
    char *five = "jkl";
    char *six = "mno";
    char *seven = "pqrs";
    char *eight = "tuv";
    char *nine = "wxyz";
    char *board[10] = {zero, one, two, three, four, five, six, seven, eight, nine};
    int *f = calloc(100001, sizeof(int));
    long long ans = 1;
    int left = 0;
    for (int right = 0; pressedKeys[right] != '\0'; right++)
    {
        if (pressedKeys[right] != pressedKeys[right + 1])
        {
            ans *= (func(pressedKeys, left, right - left + 1, f, board) % 1000000007);
            ans %= 1000000007;
            left = right + 1;
        }
    }
    return ans;
}

int func(char *pressedKeys, int start, int len, int *f, char **board){
    f[0] = 1;
    int n_len = strlen(board[pressedKeys[start] - 48]);
    for (int l = 1; l <= len; l++)
    {
        f[l] = 0;
        for (int i = 1; i <= n_len; i++)
        {
            f[l] += l < i ? 0 : f[l - i];
            f[l] %= 1000000007;
        }
    }
    return f[len];
}