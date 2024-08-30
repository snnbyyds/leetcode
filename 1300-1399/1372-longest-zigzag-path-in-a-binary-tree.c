/* https://leetcode.cn/problems/longest-zigzag-path-in-a-binary-tree/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
int longestZigZag(struct TreeNode* root);
void dfs(struct TreeNode* node, bool dir, int len);

int ans;

int main(void){
    struct TreeNode *root = NULL;
    int empty = -1;
    int data[17] = {1, -1, 1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, -1, 1, -1, 1};
    create(data, 17, empty, &root);
    printf("%d\n", longestZigZag(root));
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

int longestZigZag(struct TreeNode* root){
    if (root == NULL)
    {
        return 0;
    }
    ans = 0;
    dfs(root, true, 0);
    dfs(root, false, 0);
    return ans;
}

void dfs(struct TreeNode* node, bool dir, int len){
    ans = MAX(ans, len);
    if (dir) // left first
    {
        if (node->left != NULL)
        {
            dfs(node->left, true, 1);
        }
        if (node->right != NULL)
        {
            dfs(node->right, false, len + 1);
        }
    }
    else
    {
        if (node->left != NULL)
        {
            dfs(node->left, true, len + 1);
        }
        if (node->right != NULL)
        {
            dfs(node->right, false, 1);
        }
    }
}