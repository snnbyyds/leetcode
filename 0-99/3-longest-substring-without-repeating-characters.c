/* https://leetcode.cn/problems/longest-substring-without-repeating-characters/ */

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s);

int main(void){
    char *s = "abcabcbb";
    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}

int lengthOfLongestSubstring(char* s){
    bool arr[128] = {false};
    int ans = 0;
    int left = 0;
    for (int right = 0; right < strlen(s); right++)
    {
        while (arr[s[right]] && left <= right)
        {
            arr[s[left++]] = false;
        }
        arr[s[right]] = true;
        ans = MAX(ans, right - left + 1);
    }
    return ans;    
}