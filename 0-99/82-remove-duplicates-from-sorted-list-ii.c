/* https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/ */

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
    int data[7] = {1, 2, 3, 3, 4, 4 ,5};
    for (int i = 0; i < 7; i++)
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
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = -114514;
    dummy->next = head;
    struct ListNode *cur = dummy;
    int val;
    while (cur->next != NULL && cur->next->next != NULL)
    {
        val = cur->next->val;
        if (cur->next->next->val == val)
        {
            while (cur->next != NULL && cur->next->val == val)
            {
                cur->next = cur->next->next;
            }
        }
        else
        {
            cur = cur->next;
        }   
    }
    return dummy->next;
}