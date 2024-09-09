/* https://leetcode.cn/problems/additive-number/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool isAdditiveNumber(char* num);
void backtrack(bool *ans, char *num, int numlength, int *path, int top, int startidx);
bool valid(char *num, int numlength, int *path, int top);

int main(void){
    char *num = "11111111111011111111111";
    if (isAdditiveNumber(num))
    {
        printf("%s is Additive Number\n", num);
    }
    else
    {
        printf("%s is not Additive Number\n", num);
    }
    return 0;
}

bool isAdditiveNumber(char* num){
    int numlength = strlen(num);
    if (numlength < 3)
    {
        return false;
    }
    bool ans = false;
    int *path = malloc(sizeof(int) * numlength); // contains pos of comma
    backtrack(&ans, num, numlength, path, 0, 0);
    return ans;
}

void backtrack(bool *ans, char *num, int numlength, int *path, int top, int startidx){   
    if (*ans)
    {
        return;
    }
    if (top >= 2)
    {
        *ans = (valid(num, numlength, path, top) || *ans);
        if (startidx == numlength - 1 || *ans)
        {
            return;
        }
    }
    for (int i = startidx; i < numlength - 1; i++)
    {
        if (top >= 2 && i - path[top - 1] < path[top - 1] - path[top - 2])
        {
            continue;
        }
        path[top] = i;
        backtrack(ans, num, numlength, path, top + 1, i + 1);
    }
}

bool valid(char *num, int numlength, int *path, int top){
    char *piece = malloc(sizeof(char) * (numlength + 1));
    long long *fragments = malloc(sizeof(long long) * numlength);
    int frag_idx = 0;
    memcpy(piece, num, sizeof(char) * (path[0] + 1));
    piece[path[0] + 1] = '\0';
    if (strlen(piece) > 1 && piece[0] == '0')
    {
        return false;
    }
    fragments[frag_idx++] = atoll(piece);
    for (int i = 0; i < top - 1; i++)
    {
        memcpy(piece, &num[path[i] + 1], sizeof(char) * (path[i + 1] - path[i]));
        piece[path[i + 1] - path[i]] = '\0';
        if (strlen(piece) > 1 && piece[0] == '0')
        {
            return false;
        }
        fragments[frag_idx++] = atoll(piece);
    }
    memcpy(piece, &num[path[top - 1] + 1], sizeof(char) * (numlength - 1 - path[top - 1]));
    piece[numlength - 1 - path[top - 1]] = '\0';
    if (strlen(piece) > 1 && piece[0] == '0')
    {
        return false;
    }
    fragments[frag_idx++] = atoll(piece);
    for (int i = 2; i < frag_idx; i++)
    {
        if (fragments[i] - fragments[i - 1] != fragments[i - 2])
        {
            return false;
        }
    }
    return true;
}