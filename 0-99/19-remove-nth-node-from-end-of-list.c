/* https://leetcode.cn/problems/remove-nth-node-from-end-of-list/ */

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* initnode(int num);
void appendnode(struct ListNode *newnode, struct ListNode **head);
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

int main(void){
    struct ListNode *head = NULL;
    int data[5] = {1, 2, 3, 4, 5};
    int n = 2;
    for (int i = 0; i < 5; i++)
    {
        appendnode(initnode(data[i]), &head);
    }
    for (struct ListNode *i = removeNthFromEnd(head, n); i != NULL; i = i->next)
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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    dummy->val = -1;
    struct ListNode *left = dummy;
    struct ListNode *right = dummy;
    // right go first (n steps)
    for (int i = 0; i < n; i++)
    {
        right = right->next;
    }
    // left will be the (n + 1)th node from the end
    while (right != NULL && right->next != NULL)
    {
        right = right->next;
        left = left->next;
    }
    // del
    struct ListNode *nxt = left->next;
    left->next = nxt->next;
    free(nxt);
    return dummy->next;
}