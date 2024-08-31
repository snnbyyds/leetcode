/* https://leetcode.cn/problems/minimum-absolute-difference-in-bst/ */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
int getMinimumDifference(struct TreeNode* root);
void dfs(struct TreeNode* root, int *min, int *pre);

int main(void){
    int data[5] = {4, 2, 6, 1, 3};
    int empty = -1;
    struct TreeNode *root = NULL;
    create(data, 5, empty, &root);
    printf("%d\n", getMinimumDifference(root));
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

int getMinimumDifference(struct TreeNode* root){
    int min = INT_MAX;
    int pre = -1;
    dfs(root, &min, &pre);
    return min;
}

void dfs(struct TreeNode* root, int *min, int *pre){
    if (root == NULL)
    {
        return;
    }
    dfs(root->left, min, pre);
    if (*pre == -1)
    {
        *pre = root->val;
    }
    else
    {
        *min = MIN(*min, root->val - (*pre));
        *pre = root->val;
    }
    dfs(root->right, min, pre);
}