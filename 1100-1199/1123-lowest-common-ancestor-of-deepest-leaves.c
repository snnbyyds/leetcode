/* https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/ */

#include<stdio.h>
#include<stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
struct TreeNode* lcaDeepestLeaves(struct TreeNode* root);
int getdepth(struct TreeNode *root);

int main(void){
    int data[] = {1, 2, 3, 4, 5, 6, 7};
    int empty = -1;
    struct TreeNode *root = NULL;
    create(data, sizeof(data) / sizeof(int), empty, &root);
    printf("%d\n", lcaDeepestLeaves(root)->val);
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

struct TreeNode* lcaDeepestLeaves(struct TreeNode* root){
    struct TreeNode* ans = root;
    struct TreeNode* cur = root;
    int l_depth, r_depth;
    while (cur != NULL)
    {
        l_depth = getdepth(cur->left);
        r_depth = getdepth(cur->right);
        if (l_depth == r_depth)
        {
            ans = cur;
            break;
        }
        else if (l_depth > r_depth)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    return ans;
}

int getdepth(struct TreeNode *root){
    if (root == NULL)
    {
        return 0;
    }
    int l_depth = getdepth(root->left);
    int r_depth = getdepth(root->right);
    return MAX(l_depth, r_depth) + 1;
}