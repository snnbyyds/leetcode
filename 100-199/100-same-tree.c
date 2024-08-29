/* https://leetcode.cn/problems/same-tree/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
bool isSameTree(struct TreeNode* p, struct TreeNode* q);

int main(void){
    struct TreeNode *root1 = NULL;
    struct TreeNode *root2 = NULL;
    int empty = -100001;
    int data1[3] = {1, 2, 3};
    int data2[3] = {1, 2, 3};
    create(data1, 3, empty, &root1);
    create(data2, 3, empty, &root2);
    printf("%d\n", (isSameTree(root1, root2) ? 1 : 0));
    return 0;
}

void create(int *nums, int numsSize, int empty, struct TreeNode **root){
    if (nums[0] == empty || numsSize == 0)
    {
        return;
    }
    struct TreeNode **queue = malloc(sizeof(struct TreeNode *) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != empty)
        {
            queue[i] = initnode(nums[i]);
        }
        else
        {
            queue[i] = NULL;
        }
    }
    int head = 0;
    int rear = 0;
    int start = 0;
    *root = queue[rear++];
    while (head != rear && rear < numsSize)
    {
        head = rear;
        while (start < head && rear < numsSize)
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

struct TreeNode *initnode(int value){
    struct TreeNode *newnode = malloc(sizeof(struct TreeNode));
    newnode->val = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL || q == NULL)
    {
        return (p == q);
    }
    return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}