/* https://leetcode.cn/problems/double-a-number-represented-as-a-linked-list/ */

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* initnode(int num);
void appendnode(struct ListNode *newnode, struct ListNode **head);
struct ListNode* doubleIt(struct ListNode* head);

int main(void){
    struct ListNode *head = NULL;
    int data[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        appendnode(initnode(data[i]), &head);
    }
    for (struct ListNode *i = doubleIt(head); i != NULL; i = i->next)
    {
        printf("%d", i->val);
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

struct ListNode* doubleIt(struct ListNode* head){
    if (head->val > 4)
    {
        struct ListNode *p = malloc(sizeof(struct ListNode));
        p->val = 0;
        p->next = head;
        head = p;
    }
    for (struct ListNode *i = head; i != NULL; i = i->next)
    {
        i->val = i->val * 2 % 10;
        if (i->next != NULL && i->next->val > 4)
        {
            i->val++;
        }
    }
    return head;
}