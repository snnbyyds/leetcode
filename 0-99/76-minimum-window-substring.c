/* https://leetcode.cn/problems/minimum-window-substring/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MIN(a, b) ((a) > (b) ? (a) : (b))

char* minWindow(char* s, char* t);
bool covered(int *s_arr, int *t_arr);

int main(void){
    char *s = "ADOBECODEBANC";
    char *t = "ABC";
    printf("%s\n", minWindow(s, t));
    return 0;
}

char* minWindow(char* s, char* t) {
    int t_arr[128] = {0};
    int t_len = strlen(t);
    for (int i = 0; i < t_len; i++)
    {
        t_arr[t[i]]++;
    }
    
    int s_arr[128] = {0};
    int s_len = strlen(s);
    int left = 0;
    bool is_covered;
    int ans_left = -1;
    int ans_right = s_len;
    for (int right = 0; right < s_len; right++)
    {
        s_arr[s[right]]++;
        is_covered = false;
        while (covered(s_arr, t_arr))
        {
            if (right - left < ans_right - ans_left)
            {
                ans_left = left;
                ans_right = right;
            }
            s_arr[s[left]]--;
            left++;
        }
    }
    if (ans_left != -1)
    {
        char *res = malloc((ans_right - ans_left + 2) * sizeof(char));
        *res = '\0';
        strncat(res, s + ans_left, ans_right - ans_left + 1);
        return res;
    }
    return "";
}

bool covered(int *s_arr, int *t_arr){
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (s_arr[i] < t_arr[i])
        {
            return false;
        }
    }
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (s_arr[i] < t_arr[i])
        {
            return false;
        }
    }
    return true;
}