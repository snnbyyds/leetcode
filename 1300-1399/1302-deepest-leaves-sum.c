/* https://leetcode.cn/problems/deepest-leaves-sum/ */

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
int deepestLeavesSum(struct TreeNode* root);
void dfs(struct TreeNode *root, int *sum, int *maxdepth, int depth);

int main(void){
    int data[] = {5, 8, 9, 2, 1, 3, 7, 4, 6};
    int empty = -1;
    struct TreeNode *root = NULL;
    create(data, sizeof(data) / sizeof(int), empty, &root);
    printf("%d\n", deepestLeavesSum(root));
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

int deepestLeavesSum(struct TreeNode* root){
    int maxdepth = -1;
    int depth = 1;
    int sum = 0;
    dfs(root, &sum, &maxdepth, depth);
    return sum;
}

void dfs(struct TreeNode *root, int *sum, int *maxdepth, int depth){
    if (root == NULL)
    {
        return;
    }
    if (depth > *maxdepth)
    {
        *maxdepth = depth;
        *sum = root->val;
    }
    else if (depth == *maxdepth)
    {
        *sum += root->val;
    }
    dfs(root->left, sum, maxdepth, depth + 1);
    dfs(root->right, sum, maxdepth, depth + 1);
}