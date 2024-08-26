/* https://leetcode.cn/problems/reorder-list/ */

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* initnode(int num);
void appendnode(struct ListNode *newnode, struct ListNode **head);
void reorderList(struct ListNode* head);

int main(void){
    struct ListNode *head = NULL;
    int data[4] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++)
    {
        appendnode(initnode(data[i]), &head);
    }
    reorderList(head);
    for (struct ListNode *i = head; i != NULL; i = i->next)
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

void reorderList(struct ListNode* head){
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode *cur = slow->next;
    slow->next = NULL;
    struct ListNode *pre = NULL;
    struct ListNode *nxt;
    // do reverse
    // (head)1->2->3 (pre)5->4
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    struct ListNode *ins = pre;
    struct ListNode *nxt2;
    while (ins != NULL)
    {
        nxt = head->next;
        nxt2 = ins->next;
        head->next = ins;
        ins->next = nxt;
        ins = nxt2;
        if (head != NULL && head->next != NULL)
        {
            head = head->next->next;
        }
    }
}