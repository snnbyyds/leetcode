/* https://leetcode.cn/problems/validate-binary-search-tree/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
bool isValidBST(struct TreeNode* root);
bool f(struct TreeNode *node, long long left, long long right);

int main(void){
    struct TreeNode *root = NULL;
    int empty = -1;
    int data[7] = {5, 1, 4, -1, -1, 3, 6};
    create(data, 7, empty, &root);
    printf("%d\n", isValidBST(root) ? 1 : 0);
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

bool isValidBST(struct TreeNode* root){
    long long left = LLONG_MIN;
    long long right = LLONG_MAX;
    return f(root, left, right);
}

bool f(struct TreeNode *node, long long left, long long right){
    if (node == NULL)
    {
        return true;
    }
    return node->val > left && node->val < right && f(node->left, left, node->val) && f(node->right, node->val, right);
}