/* https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/ */

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

void create(int *data, int dataSize, int empty, struct Node **root);
struct Node *initnode(int value);
struct Node *connect(struct Node* root);

int main(void){
    struct Node *root = NULL;
    int data[7] = {1, 2, 3, 4, 5, 6, 7};
    int empty = -1001;
    create(data, 7, empty, &root);
    struct Node *newroot = connect(root);
    for (struct Node *i = newroot; i != NULL; i = i->left)
    {
        for (struct Node *j = i; j != NULL; j = j->next)
        {
            printf("%d\t", j->val);
        }
        printf("\n");
    }    
    return 0;
}

void create(int *data, int dataSize, int empty, struct Node **root){
    if (data[0] == empty)
    {
        return;
    }
    struct Node **queue = malloc(sizeof(struct Node*) * dataSize);
    for (int i = 0; i < dataSize; i++)
    {
        if (data[i] == empty)
        {
            queue[i] = NULL;
        }
        else
        {
            queue[i] = initnode(data[i]);
        }
    }
    int head = 0;
    int rear = 0;
    int start = 0;
    *root = queue[rear++];
    while (head != rear && rear < dataSize)
    {
        head = rear;
        while (start < head && rear < dataSize)
        {
            if (queue[start] != NULL)
            {
                queue[start]->left = queue[rear++];
                queue[start]->right = queue[rear++];
            }
            start++;
        }
    }
}

struct Node *initnode(int value){
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode->val = value;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->next = NULL;
    return newnode;
}

struct Node *connect(struct Node* root){
    if (root == NULL)
    {
        return NULL;
    }
    struct Node *queue[4096];
    int start;
    int head = 0;
    int rear = 0;
    queue[rear++] = root;
    while (head != rear)
    {
        start = head;
        head = rear;
        for (int i = start; i < head; i++)
        {
            queue[i]->next = (i < head - 1 ? queue[i + 1] : NULL);
            if (queue[i]->left != NULL)
            {
                queue[rear++] = queue[i]->left;
            }
            if (queue[i]->right != NULL)
            {
                queue[rear++] = queue[i]->right;
            }
        }
    }
    return root;
}