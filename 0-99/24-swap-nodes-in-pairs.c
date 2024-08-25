/* https://leetcode.cn/problems/swap-nodes-in-pairs/ */

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* initnode(int num);
void appendnode(struct ListNode *newnode, struct ListNode **head);
struct ListNode* swapPairs(struct ListNode* head);

int main(void){
    struct ListNode *head = NULL;
    int data[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        appendnode(initnode(data[i]), &head);
    }
    for (struct ListNode *i = swapPairs(head); i != NULL; i = i->next)
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

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    int len = 0;
    for (struct ListNode *i = head; i != NULL; i = i->next)
    {
        len++;
    }
    struct ListNode *pre;
    struct ListNode *cur;
    struct ListNode *nxt;
    struct ListNode *p0 = dummy;
    while (len >= 2)
    {
        len -= 2;
        pre = NULL;
        cur = p0->next;
        for (int i = 0; i < 2; i++)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        nxt = p0->next;
        p0->next->next = cur;
        p0->next = pre;
        p0 = nxt;
    }
    return dummy->next;
}