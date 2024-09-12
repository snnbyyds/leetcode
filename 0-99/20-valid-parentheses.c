/* https://leetcode.cn/problems/valid-parentheses/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool isValid(char* s);

int main(void){
    // printf("%d %d %d %d %d %d\n", '(', ')', '{', '}', '[', ']');
    char *s = "()[]{}";
    printf("%s\n", isValid(s) ? "valid" : "invalid");
    return 0;
}

bool isValid(char* s){
    int len_s = strlen(s);
    char *stack = malloc(sizeof(char) * len_s);
    int stack_top = 0;
    for (int i = 0; i < len_s; i++)
    {   
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack[stack_top++] = s[i];
        }
        else if (stack_top > 0 && s[i] - stack[stack_top - 1] < 3 && s[i] - stack[stack_top - 1] > 0) // 40 41 123 125 91 93 | '(', ')', '{', '}', '[', ']'
        {
            stack_top--;
        }
        else
        {
            return false;
        }
    }
    return stack_top == 0;
}