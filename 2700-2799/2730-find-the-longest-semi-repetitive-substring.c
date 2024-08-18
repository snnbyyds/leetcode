/* https://leetcode.cn/problems/find-the-longest-semi-repetitive-substring/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestSemiRepetitiveSubstring(char * s);

int main(void){
    char *s = "52233";
    printf("%d\n", longestSemiRepetitiveSubstring(s));
    return 0;
}

int longestSemiRepetitiveSubstring(char * s){
    int len = strlen(s);
    if (len == 1)
    {
        return 1;
    }
    
    int ans = 0;
    int left = 0;
    int cnt = 0;
    for (int right = 1; right < len; right++)
    {
        cnt += (s[right] == s[right - 1]);
        if (cnt == 2)
        {
            left++;
            while (s[left] != s[left + 1])
            {
                left++;
            }
            cnt = 1;
        }
        ans = MAX(ans, right - left + 1);
    }
    return ans;
}