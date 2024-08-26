/* https://leetcode.cn/problems/palindrome-linked-list/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* initnode(int num);
void appendnode(struct ListNode *newnode, struct ListNode **head);
bool isPalindrome(struct ListNode* head);

int main(void){
    struct ListNode *head = NULL;
    int data[4] = {1, 2, 2, 1};
    for (int i = 0; i < 4; i++)
    {
        appendnode(initnode(data[i]), &head);
    }
    printf("%d\n", (isPalindrome(head) ? 1 : 0));
    struct ListNode *cur = head;
    struct ListNode *nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
    return 0;
}

struct ListNode* initnode(int num){
    struct ListNode *newnode = malloc(sizeof(struct ListNode));
    newnode->next = NULL;
    newnode->val = num;
    return newnode;
}

void appendnode(struct ListNode *newnode, struct ListNode **head){
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        appendnode(newnode, &((*head)->next));
    }
}

bool isPalindrome(struct ListNode* head){
    // get mid
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // reverse second half
    struct ListNode *pre = NULL;
    struct ListNode *cur = slow;
    struct ListNode *nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    // cmp
    while (head != NULL && pre != NULL)
    {
        if (head->val != pre->val)
        {
            return false;
        }
        head = head->next;
        pre = pre->next;
    }
    return true;
}