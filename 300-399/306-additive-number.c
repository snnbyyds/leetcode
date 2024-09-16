/* https://leetcode.cn/problems/additive-number/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool isAdditiveNumber(char* num);
void backtrack(bool *ans, char *num, int numlength, char **path, int top);
bool valid(char **path, int top);
// void backtrack(bool *ans, char *num, int numlength, int *path, int top, int startidx);
// bool valid(char *num, int numlength, int *path, int top);

int main(void){
    char *num = "199111992";
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
    char **path = malloc(sizeof(char*) * numlength); // contains fragments
    backtrack(&ans, num, numlength, path, 0);
    return ans;
}

void backtrack(bool *ans, char *num, int numlength, char **path, int top){
    if (*num == '\0')
    {
        *ans = *ans || valid(path, top);
        return;
    }
    int len = strlen(num);
    for (int i = 0; i < len; i++)
    {
        if (*ans)
        {
            return;
        }
        if (top >= 3 && i + 1 < strlen(path[top - 1]))
        {
            continue;
        }
        if (num[0] == '0' && i > 0)
        {
            continue;
        }
        path[top] = malloc(sizeof(char) * (i + 2));
        strncpy(path[top], num, i + 1);
        path[top][i + 1] = '\0';
        backtrack(ans, num + i + 1, numlength, path, top + 1);
    }
}

bool valid(char **path, int top){
    if (top < 3)
    {
        return false;
    }
    for (int i = 2; i < top; i++)
    {
        if (atoll(path[i]) - atoll(path[i - 1]) != atoll(path[i - 2]))
        {
            return false;
        }
    }
    return true;
}

/*
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
*/