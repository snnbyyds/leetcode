/* https://leetcode.cn/problems/binary-tree-paths/ */

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
char** binaryTreePaths(struct TreeNode* root, int* returnSize);
void backtrack(struct TreeNode* root, int* returnSize, char **ans, int *path, int top);

int main(void){
    struct TreeNode *root = NULL;
    int data[] = {37, -34, -48, -1, -100, -100, 48, -1, -1, -1, -1, -54, -1, -71, -22, -1, -1, -1, 8};
    int empty = -1;
    create(data, sizeof(data) / sizeof(int), empty, &root);
    int returnSize;
    char **ans = binaryTreePaths(root, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%s\n", ans[i]);
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

char** binaryTreePaths(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    char **ans = malloc(sizeof(char*) * 101);
    ans[0] = malloc(sizeof(char) * 101);
    int path[1001];
    backtrack(root, returnSize, ans, path, 0);
    return ans;
}

void backtrack(struct TreeNode* root, int* returnSize, char **ans, int *path, int top){
    if (root == NULL)
    {
        return;
    }
    char *s = malloc(sizeof(char) * 7);
    if (root->left == root->right)
    {
        ans[*returnSize] = malloc(sizeof(char) * 1001);
        ans[*returnSize][0] = '\0';
        for (int i = 0; i < top; i++)
        {
            sprintf(s, "%d->", path[i]);
            strcat(ans[*returnSize], s);
        }
        sprintf(s, "%d", root->val);
        strcat(ans[(*returnSize)++], s);
    }
    else
    {
        path[top] = root->val;
        backtrack(root->left, returnSize, ans, path, top + 1);
        backtrack(root->right, returnSize, ans, path, top + 1);
    }
}