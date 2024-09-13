/* https://leetcode.cn/problems/restore-ip-addresses/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

char** restoreIpAddresses(char* s, int* returnSize);
void backtrack(char **ans, char *s, int orig_len, int *returnSize, char **path, int top, int cnt);

int main(void){
    char *s = "25525511135";
    int returnSize;
    char **ans = restoreIpAddresses(s, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%s\n", ans[i]);
    }
    return 0;
}

char** restoreIpAddresses(char* s, int* returnSize){
    *returnSize = 0;
    int len_s = strlen(s);
    if (len_s < 4 || len_s > 12)
    {
        return NULL;
    }
    char **ans = malloc(sizeof(char*) * 524288); // (int)pow(2, 19) == 524288
    char **path = malloc(sizeof(char*) * len_s);
    backtrack(ans, s, len_s, returnSize, path, 0, 0);
    return ans;
}

void backtrack(char **ans, char *s, int orig_len, int *returnSize, char **path, int top, int cnt){
    if ((4 - top) * 3 < orig_len - cnt)
    {
        return;
    }
    if (*s == '\0' && top == 4 && atoi(path[top - 1]) <= 255)
    {
        ans[*returnSize] = malloc(sizeof(char) * (orig_len + top));
        ans[*returnSize][0] = '\0';
        for (int i = 0; i < top - 1; i++)
        {
            strcat(ans[*returnSize], path[i]);
            strcat(ans[*returnSize], ".");
        }
        strcat(ans[(*returnSize)++], path[top - 1]);
        return;
    }
    int len_s = strlen(s);
    for (int i = 0; i < len_s; i++)
    {
        if (top >= 1 && atoi(path[top - 1]) > 255)
        {
            continue;
        }
        if (s[0] == '0' && i >= 1)
        {
            continue;
        }
        path[top] = malloc(sizeof(char) * (i + 2));
        strncpy(path[top], s, i + 1);
        path[top][i + 1] = '\0';
        backtrack(ans, s + i + 1, orig_len, returnSize, path, top + 1, cnt + i + 1);
    }
}

/*
struct ret {
    bool is_valid;
    char **fragments;
    int fragmentsSize;
};

char** restoreIpAddresses(char* s, int* returnSize);
void backtrack(char **ans, char* s, int len_s, int* returnSize, int *path, int top, int startidx);
struct ret isvalidIpAddress(char* s, int len_s, int* returnSize, int *path, int top);

int main(void){
    char *s = "25525511135";
    int returnSize;
    char **ans = restoreIpAddresses(s, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%s\n", ans[i]);
    }
    return 0;
}

char** restoreIpAddresses(char* s, int* returnSize){
    *returnSize = 0;
    int len_s = strlen(s);
    if (len_s < 4 || len_s > 12)
    {
        return NULL;
    }
    char **ans = malloc(sizeof(char*) * 524288); // (int)pow(2, 19) == 524288
    int *path = malloc(sizeof(int) * (len_s - 1));
    backtrack(ans, s, len_s, returnSize, path, 0, 0);
    return ans;
}

void backtrack(char **ans, char* s, int len_s, int* returnSize, int *path, int top, int startidx){
    if (top > 0 && (path[top - 1] + 1 > top * 3 || len_s - path[top - 1] - 4 + top <= 0))
    {
        return;
    }
    if (top == 3)
    {
        struct ret pathinfo = isvalidIpAddress(s, len_s, returnSize, path, top);
        if (pathinfo.is_valid)
        {
            ans[*returnSize] = malloc(sizeof(char) * (len_s + pathinfo.fragmentsSize));
            ans[*returnSize][0] = '\0';
            for (int i = 0; i < pathinfo.fragmentsSize - 1; i++)
            {
                strcat(ans[*returnSize], pathinfo.fragments[i]);
                strcat(ans[*returnSize], ".");
            }
            strcat(ans[(*returnSize)++], pathinfo.fragments[pathinfo.fragmentsSize - 1]);
        }
        return;
    }
    for (int i = startidx; i < len_s - 1; i++)
    {
        path[top] = i;
        backtrack(ans, s, len_s, returnSize, path, top + 1, i + 1);
    }
}

struct ret isvalidIpAddress(char* s, int len_s, int* returnSize, int *path, int top){
    struct ret res;
    res.fragments = malloc(len_s * sizeof(char*));
    int fragments_idx = 0;
    res.fragments[fragments_idx] = malloc((path[0] + 2) * sizeof(char));
    memcpy(res.fragments[fragments_idx], s, sizeof(char) * (path[0] + 1));
    res.fragments[fragments_idx][path[0] + 1] = '\0';
    if ((path[0] > 0 && res.fragments[fragments_idx][0] == '0') || atoi(res.fragments[fragments_idx]) > 255)
    {
        res.is_valid = false;
        return res;
    }
    fragments_idx++;
    for (int i = 0; i < top - 1; i++)
    {
        res.fragments[fragments_idx] = malloc(sizeof(char) * (path[i + 1] - path[i] + 1));
        memcpy(res.fragments[fragments_idx], &s[path[i] + 1], sizeof(char) * (path[i + 1] - path[i]));
        res.fragments[fragments_idx][path[i + 1] - path[i]] = '\0';
        if ((path[i + 1] - path[i] > 1 && res.fragments[fragments_idx][0] == '0') || atoi(res.fragments[fragments_idx]) > 255)
        {
            res.is_valid = false;
            return res;
        }
        fragments_idx++;
    }
    res.fragments[fragments_idx] = malloc(sizeof(char) * (len_s - path[top - 1]));
    memcpy(res.fragments[fragments_idx], &s[path[top - 1] + 1], sizeof(char) * (len_s - 1 - path[top - 1]));
    res.fragments[fragments_idx][len_s - 1 - path[top - 1]] = '\0';
    if ((len_s - path[top - 1] > 2 && res.fragments[fragments_idx][0] == '0') || atoi(res.fragments[fragments_idx]) > 255)
    {
        res.is_valid = false;
        return res;
    }
    res.fragmentsSize = ++fragments_idx;
    res.is_valid = true;
    return res;
}
*/