/* https://leetcode.cn/problems/reverse-linked-list-ii/ */

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* initnode(int num);
void appendnode(struct ListNode *newnode, struct ListNode **head);
struct ListNode* reverseBetween(struct ListNode* head, int left, int right);

int main(void){
    struct ListNode *head = NULL;
    int data[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        appendnode(initnode(data[i]), &head);
    }
    for (struct ListNode *i = reverseBetween(head, 2, 4); i != NULL; i = i->next)
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

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    struct ListNode *p0 = dummy;
    for (int i = 0; i < left - 1; i++)
    {
        p0 = p0->next;
    }
    struct ListNode *pre = NULL;
    struct ListNode *cur = p0->next;
    struct ListNode *nxt = NULL;
    for (int i = 0; i < right - left + 1; i++)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    p0->next->next = cur;
    p0->next = pre;
    return dummy->next;
}