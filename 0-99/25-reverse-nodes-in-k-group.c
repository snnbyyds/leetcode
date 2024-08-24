/* https://leetcode.cn/problems/reverse-nodes-in-k-group/ */

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* initnode(int num);
void appendnode(struct ListNode *newnode, struct ListNode **head);
struct ListNode* reverseKGroup(struct ListNode* head, int k);

int main(void){
    struct ListNode *head = NULL;
    int data[5] = {1, 2, 3, 4, 5};
    int k = 2;
    for (int i = 0; i < 5; i++)
    {
        appendnode(initnode(data[i]), &head);
    }
    for (struct ListNode *i = reverseKGroup(head, k); i != NULL; i = i->next)
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

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    dummy->val = -1;
    int len = 0;
    for (struct ListNode *i = head; i != NULL; i = i->next)
    {
        len++;
    }
    struct ListNode *p0 = dummy;
    struct ListNode *pre;
    struct ListNode *cur;
    struct ListNode *nxt;
    while (len >= k)
    {
        len -= k;
        pre = NULL;
        cur = p0->next;
        for (int i = 0; i < k; i++)
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