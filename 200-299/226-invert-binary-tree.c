/* https://leetcode.cn/problems/invert-binary-tree/ */

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
void levelOrder(struct TreeNode *root);
struct TreeNode* invertTree(struct TreeNode* root);

int main(void){
    int data[7] = {4, 2, 7, 1, 3, 6, 9};
    struct TreeNode *root = NULL;
    int empty = -101;
    create(data, 7, empty, &root);
    struct TreeNode *new = invertTree(root);
    levelOrder(new);
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

void levelOrder(struct TreeNode *root){
    if (root == NULL)
    {
        return;
    }
    struct TreeNode *queue[2000];
    int head = 0;
    int rear = 0;
    int start;
    queue[rear++] = root;
    while (head != rear)
    {
        start = head;
        head = rear;
        for (int i = start; i < head; i++)
        {
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
    for (int i = 0; i < rear; i++)
    {
        printf("%d ", queue[i]->val);
    }
    printf("\n");
}

struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL)
    {
        return root;
    }
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}