/* https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/ */

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
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes);
int getdepth(struct TreeNode* root);

int main(void){
    int empty = -1;
    int data[11] = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    struct TreeNode *root = NULL;
    create(data, 11, empty, &root);
    int returnSize;
    int *returnColumnSizes;
    int **ans = levelOrderBottom(root, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
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

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = getdepth(root);
    int **ans = malloc(sizeof(int*) * (*returnSize));
    struct TreeNode *queue[2001];
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    int start;
    int head = 0;
    int rear = 0;
    int delta = 1;
    queue[rear++] = root;
    while (head != rear)
    {
        ans[*returnSize - delta] = malloc(sizeof(int) * (rear - head));
        (*returnColumnSizes)[*returnSize - delta] = rear - head;
        start = head;
        head = rear;
        for (int i = start; i < head; i++)
        {
            ans[*returnSize - delta][i - start] = queue[i]->val;
            if (queue[i]->left != NULL)
            {
                queue[rear++] = queue[i]->left;
            }
            if (queue[i]->right != NULL)
            {
                queue[rear++] = queue[i]->right;
            }
        }
        delta++;
    }
    return ans;
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