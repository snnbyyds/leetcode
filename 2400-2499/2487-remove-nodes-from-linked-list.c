/* https://leetcode.cn/problems/remove-nodes-from-linked-list/ */

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* initnode(int num);
void appendnode(struct ListNode *newnode, struct ListNode **head);
struct ListNode* removeNodes(struct ListNode* head);
struct ListNode* reverse(struct ListNode* head);

int main(void){
    struct ListNode *head = NULL;
    int data[5] = {5, 2, 13, 3, 8};
    for (int i = 0; i < 5; i++)
    {
        appendnode(initnode(data[i]), &head);
    }
    for (struct ListNode *i = removeNodes(head); i != NULL; i = i->next)
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

struct ListNode* removeNodes(struct ListNode* head){
    struct ListNode *rev = reverse(head);
    struct ListNode *left = rev;
    struct ListNode *right = rev->next;
    while (right != NULL)
    {
        if (right->val < left->val)
        {
            left->next = right->next;
            right = right->next;
        }
        else
        {
            left = right;
            right = right->next;
        }
    }
    return reverse(rev);
}

struct ListNode* reverse(struct ListNode* head){
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