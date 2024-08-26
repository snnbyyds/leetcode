/* https://leetcode.cn/problems/delete-node-in-a-linked-list/ */

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* initnode(int num);
void appendnode(struct ListNode *newnode, struct ListNode **head);
void deleteNode(struct ListNode* node);

int main(void){
    struct ListNode *head = NULL;
    int data[4] = {4, 5, 1, 9};
    for (int i = 0; i < 4; i++)
    {
        appendnode(initnode(data[i]), &head);
    }
    struct ListNode *given = head;
    int cnt = 0;
    while (cnt < 2)
    {
        given = given->next;
        cnt++;
    }
    deleteNode(given);
    for (struct ListNode *i = head; i != NULL; i = i->next)
    {
        printf("%d ", i->val);
    }
    struct ListNode *cur = head;
    struct ListNode *nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        free(cur);
        cur = nxt;
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

void deleteNode(struct ListNode* node){
    struct ListNode *nxt = node->next;
    node->val = nxt->val;
    node->next = nxt->next;
    free(nxt);
    nxt = NULL;
}