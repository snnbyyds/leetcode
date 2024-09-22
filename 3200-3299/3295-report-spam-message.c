#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool reportSpam(char** message, int messageSize, char** bannedWords, int bannedWordsSize);
int cmp(const void *a, const void *b);

int main(void){
    char *message[3] = {"hello", "world", "leetcode"};
    char *bannedWords[2] = {"world", "hello"};
    printf("%s\n", reportSpam(message, 3, bannedWords, 2) ? "true" : "false");
    return 0;
}

bool reportSpam(char** message, int messageSize, char** bannedWords, int bannedWordsSize){
    qsort(bannedWords, bannedWordsSize, sizeof(char*), cmp);
    int cnt = 0;
    for (int i = 0; i < messageSize; i++)
    {
        if (bsearch(&message[i], bannedWords, bannedWordsSize, sizeof(char*), cmp) != NULL)
        {
            cnt++;
        }
        if (cnt >= 2)
        {
            return true;
        }
    }
    return false;
}

int cmp(const void *a, const void *b){
    return strcmp(*(char**)a, *(char**)b);
}