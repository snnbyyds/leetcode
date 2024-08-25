/* https://leetcode.cn/problems/add-two-numbers/ */

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* initnode(int num);
void appendnode(struct ListNode *newnode, struct ListNode **head);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

int main(void){
    struct ListNode *head1 = NULL;
    struct ListNode *head2 = NULL;
    int data1[3] = {2, 4, 3};
    int data2[3] = {5, 6, 4};
    for (int i = 0; i < 3; i++)
    {
        appendnode(initnode(data1[i]), &head1);
        appendnode(initnode(data2[i]), &head2);
    }
    for (struct ListNode *i = addTwoNumbers(head1, head2); i != NULL; i = i->next)
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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    struct ListNode *cur = dummy;
    int carry = 0;
    int s;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        s = carry + (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0);
        cur->next = initnode(s % 10);
        carry = s / 10;
        cur = cur->next;
        if (l1 != NULL)
        {
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            l2 = l2->next;
        }
    }
    return dummy->next;
}