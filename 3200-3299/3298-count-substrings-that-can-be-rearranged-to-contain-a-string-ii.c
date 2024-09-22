/* https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

long long validSubstringCount(char* word1, char* word2);
bool valid(int *map1, int *map2);

int main(void){
    char *word1 = "abcabc";
    char *word2 = "abc";
    printf("%lld\n", validSubstringCount(word1, word2));
    return 0;
}

long long validSubstringCount(char* word1, char* word2){
    long long ans = 0;
    int *map1 = calloc(26, sizeof(int)); // maps word1;
    int *map2 = calloc(26, sizeof(int)); // maps word2;
    // get lens
    int len_word1 = strlen(word1);
    int len_word2 = strlen(word2);
    // map word2
    for (int i = 0; i < len_word2; i++)
    {
        map2[word2[i] - 'a']++;
    }
    // handle word1
    int left = 0;
    int right = -1;
    while (right < len_word1 - 1 && !valid(map1, map2))
    {
        map1[word1[++right] - 'a']++;
    }
    while (right < len_word1)
    {
        while (left <= right && valid(map1, map2))
        {
            ans += (len_word1 - right);
            map1[word1[left++] - 'a']--;
        }
        right++;
        if (right <= len_word1 - 1)
        {
            map1[word1[right] - 'a']++;
        }
    }
    return ans;
}

bool valid(int *map1, int *map2){
    for (int i = 0; i < 26; i++)
    {
        if (map1[i] < map2[i])
        {
            return false;
        }
    }
    return true;
}