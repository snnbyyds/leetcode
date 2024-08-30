/* https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/ */

#include<stdio.h>
#include<stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
int maxAncestorDiff(struct TreeNode* root);
void dfs(struct TreeNode *root, int *delta, int min, int max);

int main(void){
    struct TreeNode *root = NULL;
    int empty = -1;
    int data[12] = {8, 3, 10, 1, 6, -1, 14, -1, -1, 4, 7, 13};
    create(data, 12, empty, &root);
    printf("%d\n", maxAncestorDiff(root));
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

int maxAncestorDiff(struct TreeNode* root){
    int delta = 0;
    dfs(root, &delta, root->val, root->val);
    return delta;
}

void dfs(struct TreeNode *root, int *delta, int min, int max){
    if (root == NULL)
    {
        return;
    }
    min = MIN(root->val, min);
    max = MAX(root->val, max);
    *delta = MAX(*delta, MAX(max - root->val, root->val - min));
    dfs(root->left, delta, min, max);
    dfs(root->right, delta, min, max);
}