/* https://leetcode.cn/problems/reverse-linked-list/ */

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* initnode(int num);
void appendnode(struct ListNode *newnode, struct ListNode **head);
struct ListNode* reverseList(struct ListNode* head);

int main(void){
    struct ListNode *head = NULL;
    int data[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        appendnode(initnode(data[i]), &head);
    }
    for (struct ListNode *i = reverseList(head); i != NULL; i = i->next)
    {
        printf("%d ", i->val);
    }
    printf("\n");
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

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *cur = head;
    struct ListNode *pre = NULL;
    struct ListNode *nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}