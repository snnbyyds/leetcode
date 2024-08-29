/* https://leetcode.cn/problems/add-two-numbers-ii/ */

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
struct ListNode* reversell(struct ListNode *head);

int main(void){
    struct ListNode *head1 = NULL;
    struct ListNode *head2 = NULL;
    int data1[4] = {7, 2, 4, 3};
    int data2[3] = {5, 6, 4};
    for (int i = 0; i < 4; i++)
    {
        appendnode(initnode(data1[i]), &head1);
    }
    for (int i = 0; i < 3; i++)
    {
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
    int s;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        s = carry + (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0);
    }
    
    return reversell(dummy->next);
}

struct ListNode* reversell(struct ListNode *head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    struct ListNode *nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}