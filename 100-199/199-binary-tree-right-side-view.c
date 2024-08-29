/* https://leetcode.cn/problems/binary-tree-right-side-view/ */

#include<stdio.h>
#include<stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int *res = NULL;
int res_idx = 0;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
int* rightSideView(struct TreeNode* root, int* returnSize);
int depth(struct TreeNode* root);
void dfs(struct TreeNode* root, int dep);

int main(void){
    struct TreeNode *root = NULL;
    int empty = -101; // Use -101 to represent NULL
    int data[8] = {1, 2, 3, -101, 5, -101, 4, 7};
    create(data, 8, empty, &root);
    int returnSize;
    int *ans = rightSideView(root, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
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

int* rightSideView(struct TreeNode* root, int* returnSize){
    res = malloc(depth(root) * sizeof(int));
    res_idx = 0;
    dfs(root, 0);
    *returnSize = res_idx;
    return res;
}

int depth(struct TreeNode* root){
    if (root == NULL)
    {
        return 0;
    }
    int l_depth = depth(root->left);
    int r_depth = depth(root->right);
    return MAX(l_depth, r_depth) + 1;
}

void dfs(struct TreeNode* root, int dep){
    if (root == NULL)
    {
        return;
    }
    if (res_idx == dep)
    {
        res[dep] = root->val;
        res_idx++;
    }
    dfs(root->right, dep + 1);
    dfs(root->left, dep + 1);
}