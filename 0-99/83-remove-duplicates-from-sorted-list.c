/* https://leetcode.cn/problems/remove-duplicates-from-sorted-list/ */

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* initnode(int num);
void appendnode(struct ListNode *newnode, struct ListNode **head);
struct ListNode* deleteDuplicates(struct ListNode* head);

int main(void){
    struct ListNode *head = NULL;
    int data[5] = {1, 1, 2, 3, 3};
    for (int i = 0; i < 5; i++)
    {
        appendnode(initnode(data[i]), &head);
    }
    for (struct ListNode *i = deleteDuplicates(head); i != NULL; i = i->next)
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

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL)
    {
        return head;
    }
    struct ListNode *left = head;
    struct ListNode *right = head->next;
    while (right != NULL)
    {
        if (left->val == right->val)
        {
            left->next = right->next;
            right = left->next;
            continue;
        }
        left = left->next;
        right = right->next;
    }
    return head;
}