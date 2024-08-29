/* https://leetcode.cn/problems/binary-tree-level-order-traversal/ */

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *initnode(int value);
void appendnode(struct TreeNode *newnode, struct TreeNode **root);
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes);

int main(void){
    struct TreeNode *root = NULL;
    int data[6] = {1, 1, 4, 5, 1, 4};
    for (int i = 0; i < 6; i++)
    {
        appendnode(initnode(data[i]), &root);
    }
    int returnSize;
    int *returnColumnSizes;
    int **ans = levelOrder(root, &returnSize, &returnColumnSizes);
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

struct TreeNode *initnode(int value){
    struct TreeNode *newnode = malloc(sizeof(struct TreeNode));
    newnode->val = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void appendnode(struct TreeNode *newnode, struct TreeNode **root){
    if (*root == NULL)
    {
        *root = newnode;
    }
    else
    {
        if (newnode->val < (*root)->val)
        {
            appendnode(newnode, &(*root)->left);
        }
        else
        {
            appendnode(newnode, &(*root)->right);
        }
    }
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **ans = malloc(sizeof(int*) * 2000);
    *returnSize = 0;
    if (root == NULL)
    {
        return NULL;
    }
    struct TreeNode* queue[2000];
    int ColumnSizes[2000];
    int head = 0;
    int rear = 0;
    int start;
    queue[rear++] = root;
    while (head != rear)
    {
        ans[*returnSize] = malloc((rear - head) * sizeof(int));
        ColumnSizes[*returnSize] = rear - head;
        start = head;
        head = rear;
        for (int i = start; i < head; i++)
        {
            ans[*returnSize][i - start] = queue[i]->val;
            if (queue[i]->left != NULL)
            {
                queue[rear++] = queue[i]->left;
            }
            if (queue[i]->right != NULL)
            {
                queue[rear++] = queue[i]->right;
            }
        }
        (*returnSize)++;
    }
    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = ColumnSizes[i];
    }
    return ans;
}