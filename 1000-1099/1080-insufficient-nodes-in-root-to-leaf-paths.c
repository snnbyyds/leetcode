/* https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/ */

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
struct TreeNode* sufficientSubset(struct TreeNode* root, int limit);

int main(void){
    int data[15] = {1, 2, 3, 4, -99, -99, 7, 8, 9, -99, -99, 12, 13, -99, 14};
    int empty = -100001;
    struct TreeNode *root = NULL;
    create(data, 15, empty, &root);
    int limit = 1;
    levelOrder(sufficientSubset(root, limit));
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

struct TreeNode* sufficientSubset(struct TreeNode* root, int limit){
    if (root == NULL)
    {
        return NULL;
    }
    limit -= root->val;
    if (root->left == NULL && root->right == NULL)
    {
        return limit <= 0 ? root : NULL;
    }
    root->left = sufficientSubset(root->left, limit);
    root->right = sufficientSubset(root->right, limit);
    return (root->left != NULL || root->right != NULL) ? root : NULL;
}