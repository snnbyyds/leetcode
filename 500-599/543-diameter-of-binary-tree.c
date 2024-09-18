/* https://leetcode.cn/problems/diameter-of-binary-tree/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
int diameterOfBinaryTree(struct TreeNode* root);
int dfs(struct TreeNode *root, int *ans);

int main(void){
    struct TreeNode *root = NULL;
    int empty = -101;
    int data[] = {1, 2, 3, 4, 5, -101, 8, -101, -101, 6, 7, 9};
    create(data, sizeof(data) / sizeof(int), empty, &root);
    printf("%d\n", diameterOfBinaryTree(root));
    return 0;
}

void create(int *nums, int numsSize, int empty, struct TreeNode **root){
    if (numsSize == 0 || nums[0] == empty)
    {
        return;
    }
    struct TreeNode **queue = malloc(sizeof(struct TreeNode*) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        queue[i] = nums[i] == empty ? NULL : initnode(nums[i]);
    }
    int start = 0;
    int head = 0;
    int rear = 0;
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

int diameterOfBinaryTree(struct TreeNode* root){
    int ans = INT_MIN;
    dfs(root, &ans);
    return ans;
}

int dfs(struct TreeNode *root, int *ans){
    if (root == NULL)
    {
        return 0;
    }
    int l_depth = dfs(root->left, ans);
    int r_depth = dfs(root->right, ans);
    int ret = (l_depth > r_depth ? l_depth : r_depth) + 1;
    if (*ans < l_depth + r_depth)
    {
        *ans = l_depth + r_depth;
    }
    return ret;
}