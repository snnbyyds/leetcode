/* https://leetcode.cn/problems/univalued-binary-tree/ */

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
bool isUnivalTree(struct TreeNode* root);

int main(void){
    struct TreeNode *root = NULL;
    int empty = -1; // Use -1 to represent NULL
    int data[7] = {1, 1, 1, 1, 1, -1, 1};
    create(data, 7, empty, &root);
    printf("%d\n", isUnivalTree(root) ? 1 : 0);
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

bool isUnivalTree(struct TreeNode* root){
    if (root == NULL)
    {
        return true;
    }
    if ((root->left != NULL && root->left->val != root->val) || (root->right != NULL && root->right->val != root->val))
    {
        return false;
    }
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}