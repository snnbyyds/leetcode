/* https://leetcode.cn/problems/linked-list-cycle/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *initnode(int value);
void appendnode(struct ListNode* node, struct ListNode**head, struct ListNode **tail);
bool hasCycle(struct ListNode *head);

int main(void){
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    int data[4] = {3, 2, 0, -4};
    int pos = 1;
    for (int i = pos; i <= 4; i++)
    {
        appendnode(initnode(data[i]), &head, &tail);
    }
    for (int i = 0; i < pos; i++)
    {
        struct ListNode *new = initnode(data[i]);
        new->next = head;
        head = new;
    }
    printf("%d\n", (hasCycle(head) ? 1 : 0));
    return 0;
}

struct ListNode *initnode(int value){
    struct ListNode *newnode = malloc(sizeof(struct ListNode));
    newnode->val = value;
    newnode->next = NULL;
    return newnode;
}

void appendnode(struct ListNode* node, struct ListNode**head, struct ListNode **tail){
    if (*head == NULL && *tail == NULL)
    {
        *head = node;
        *tail = node;
        node->next = *head;
    }
    else
    {
        (*tail)->next = node;
        *tail = node;
        node->next = *head;
    }
}

bool hasCycle(struct ListNode *head){
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}