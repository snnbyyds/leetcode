/* https://leetcode.cn/problems/binary-tree-postorder-traversal/ */

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
int* postorderTraversal(struct TreeNode* root, int* returnSize);
void dfs(int *ans, struct TreeNode* root, int* returnSize);

int main(void){
    struct TreeNode *root = NULL;
    int empty = -101;
    int data[] = {1, 2, 3, 4, 5, -101, 8, -101, -101, 6, 7, 9};
    create(data, sizeof(data) / sizeof(int), empty, &root);
    int returnSize;
    int *ans = postorderTraversal(root, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d\t", ans[i]);
    }
    printf("\n");
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

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int *ans = malloc(sizeof(int) * 101);
    dfs(ans, root, returnSize);
    return ans;
}

void dfs(int *ans, struct TreeNode* root, int* returnSize){
    if (root == NULL)
    {
        return;
    }
    dfs(ans, root->left, returnSize);
    dfs(ans, root->right, returnSize);
    ans[(*returnSize)++] = root->val;
}