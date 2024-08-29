/* https://leetcode.cn/problems/balanced-binary-tree/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isBalanced(struct TreeNode* root);
int getdepth(struct TreeNode* root);
void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);

int main(void){
    struct TreeNode *root = NULL;
    int empty = -10001; // Use -10001 to represent NULL
    int data[19] = {1, 2, 2, 3, 3, -10001, -10001, 4, 4, -10001, -10001, -10001, -10001, 5, -10001, -10001, 6, -10001, 7};
    create(data, 19, empty, &root);
    printf("%d\n", (isBalanced(root) ? 1 : 0));
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

bool isBalanced(struct TreeNode* root){
    if (root == NULL)
    {
        return true;
    }
    int delta = getdepth(root->left) - getdepth(root->right);
    return delta >= -1 && delta <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int getdepth(struct TreeNode* root){
    if (root == NULL)
    {
        return 0;
    }
    int l_depth = getdepth(root->left);
    int r_depth = getdepth(root->right);
    return MAX(l_depth, r_depth) + 1;
}