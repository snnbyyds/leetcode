/* https://leetcode.cn/problems/merge-in-between-linked-lists/ */

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* initnode(int num);
void appendnode(struct ListNode *newnode, struct ListNode **head);
struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2);

int main(void){
    struct ListNode *head1 = NULL;
    struct ListNode *head2 = NULL;
    int a = 1;
    int b = 1;
    int data1[3] = {0, 1, 2};
    int data2[4] = {1000000, 1000001, 1000002, 1000003};
    for (int i = 0; i < 3; i++)
    {
        appendnode(initnode(data1[i]), &head1);
    }
    for (int i = 0; i < 4; i++)
    {
        appendnode(initnode(data2[i]), &head2);
    }
    for (struct ListNode *i = mergeInBetween(head1, a, b, head2); i != NULL; i = i->next)
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

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode *left, *right;
    struct ListNode *cur = list1;
    int cnt = 0;
    while (cur != NULL)
    {
        if (cnt == a - 1)
        {
            left = cur;
        }
        if (cnt == b + 1)
        {
            right = cur;
            break;
        }
        cnt++;
        cur = cur->next;
    }
    left->next = list2;
    cur = list2;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = right;
    return list1;
}