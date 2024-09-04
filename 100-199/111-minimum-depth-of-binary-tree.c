/* https://leetcode.cn/problems/minimum-depth-of-binary-tree/ */

#include<stdio.h>
#include<stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
int minDepth(struct TreeNode* root);
void dfs(struct TreeNode* root, int *ans, int depth);

int main(void){
    int empty = -1;
    int data[11] = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    struct TreeNode *root = NULL;
    create(data, 11, empty, &root);
    printf("%d\n", minDepth(root));
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

int minDepth(struct TreeNode* root){
    if (root == NULL)
    {
        return 0;
    }
    int ans = 100001;
    dfs(root, &ans, 1);
    return ans;
}

void dfs(struct TreeNode* root, int *ans, int depth){
    if (root == NULL)
    {
        return;
    }
    if (root->left == root->right)
    {
        *ans = MIN(*ans, depth);
    }
    dfs(root->left, ans, depth + 1);
    dfs(root->right, ans, depth + 1);
}