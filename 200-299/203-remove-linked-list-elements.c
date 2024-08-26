/* https://leetcode.cn/problems/remove-linked-list-elements/ */

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* initnode(int num);
void appendnode(struct ListNode *newnode, struct ListNode **head);
struct ListNode* removeElements(struct ListNode* head, int val);

int main(void){
    struct ListNode *head = NULL;
    int data[7] = {1, 2, 6, 3, 4, 5, 6};
    int val = 6;
    for (int i = 0; i < 7; i++)
    {
        appendnode(initnode(data[i]), &head);
    }
    for (struct ListNode *i = removeElements(head, val); i != NULL; i = i->next)
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

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode dummy = {-1, head};
    struct ListNode *cur = &dummy;
    struct ListNode *nxt;
    while (cur != NULL && cur->next != NULL)
    {
        nxt = cur->next;
        if (nxt->val == val)
        {
            cur->next = nxt->next;
            free(nxt);
        }
        else
        {
            cur = nxt;
        }
    }
    return dummy.next;
}