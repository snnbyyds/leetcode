/* https://leetcode.cn/problems/path-sum-ii/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes);
void backtrack(int **ans, struct TreeNode *root, int targetSum, int *returnSize, int **returnColumnSizes, int *path, int top);

int main(void){
    int empty = -1001;
    int data[] = {5, 4, 8, 11, -1001, 13, 4, 7, 2, -1001, -1001, 5, 1};
    struct TreeNode *root = NULL;
    create(data, sizeof(data) / sizeof(int), empty, &root);
    int targetSum = 22;
    int returnSize;
    int *returnColumnSizes;
    int **ans = pathSum(root, targetSum, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d\t", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void create(int *nums, int numsSize, int empty, struct TreeNode **root){
    if (numsSize == 0 || nums[0] == empty)
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

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL)
    {
        return NULL;
    }
    int **ans = malloc(sizeof(int*) * 5000);
    *returnColumnSizes = malloc(sizeof(int) * 5000);
    int *path = malloc(sizeof(int) * 5000);
    backtrack(ans, root, targetSum, returnSize, returnColumnSizes, path, 0);
    return ans;
}

void backtrack(int **ans, struct TreeNode *root, int targetSum, int *returnSize, int **returnColumnSizes, int *path, int top){
    if (root == NULL)
    {
        return;
    }
    if (root->left == root->right)
    {
        path[top++] = root->val;
        int sum = 0;
        for (int i = 0; i < top; i++)
        {
            sum += path[i];
        }
        if (sum == targetSum)
        {
            ans[*returnSize] = malloc(sizeof(int) * top);
            memcpy(ans[*returnSize], path, sizeof(int) * top);
            (*returnColumnSizes)[(*returnSize)++] = top;
        }
    }
    else
    {
        path[top] = root->val;
        backtrack(ans, root->left, targetSum, returnSize, returnColumnSizes, path, top + 1);
        backtrack(ans, root->right, targetSum, returnSize, returnColumnSizes, path, top + 1);
    }
}