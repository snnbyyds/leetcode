/* https://leetcode.cn/problems/symmetric-tree/ */

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
bool isSymmetric(struct TreeNode* root);
bool isSame(struct TreeNode *root1, struct TreeNode *root2);

int main(void){
    struct TreeNode *root = NULL;
    int empty = -101; // Use -101 to represent NULL
    int data[7] = {1, 2, 2, 3, 4, 4, 3};
    create(data, 7, empty, &root);
    printf("%d\n", (isSymmetric(root) ? 1 : 0));
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

bool isSymmetric(struct TreeNode* root){
    return isSame(root->left, root->right);    
}

bool isSame(struct TreeNode *root1, struct TreeNode *root2){
    if (root1 == NULL || root2 == NULL)
    {
        return (root1 == root2);
    }
    return (root1->val == root2->val && isSame(root1->left, root2->right) && isSame(root1->right, root2->left));
}