/* https://leetcode.cn/problems/delete-nodes-and-return-forest/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
void levelOrder(struct TreeNode *root);
struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize);
struct TreeNode* dfs(struct TreeNode *root, bool *map, struct TreeNode** ans, int* returnSize);

int main(void){
    int data[7] = {1, 2, 3, 4, 5, 6, 7};
    int to_delete[2] = {3, 5};
    struct TreeNode *root = NULL;
    int empty = -1;
    create(data, 7, empty, &root);
    int returnSize;
    struct TreeNode** ans = delNodes(root, to_delete, 2, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        levelOrder(ans[i]);
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

void levelOrder(struct TreeNode *root){
    if (root == NULL)
    {
        return;
    }
    struct TreeNode *queue[2000];
    int head = 0;
    int rear = 0;
    int start;
    queue[rear++] = root;
    while (head != rear)
    {
        start = head;
        head = rear;
        for (int i = start; i < head; i++)
        {
            if (queue[i]->left != NULL)
            {
                queue[rear++] = queue[i]->left;
            }
            if (queue[i]->right != NULL)
            {
                queue[rear++] = queue[i]->right;
            }
        }
    }
    for (int i = 0; i < rear; i++)
    {
        printf("%d ", queue[i]->val);
    }
    printf("\n");
}

struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize){
    *returnSize = 0;
    bool map[1001] = {false};
    struct TreeNode** ans = malloc(1001 * sizeof(struct TreeNode*));
    for (int i = 0; i < to_deleteSize; i++)
    {
        map[to_delete[i]] = true;
    }
    if (root != NULL && !map[root->val])
    {
        ans[(*returnSize)++] = root;
    }
    dfs(root, map, ans, returnSize);
    return ans;
}

struct TreeNode* dfs(struct TreeNode *root, bool *map, struct TreeNode** ans, int* returnSize){
    if (root == NULL)
    {
        return NULL;
    }
    root->left = dfs(root->left, map, ans, returnSize);
    root->right = dfs(root->right, map, ans, returnSize);
    if (map[root->val])
    {
        if (root->left != NULL)
        {
            ans[(*returnSize)++] = root->left;
        }
        if (root->right != NULL)
        {
            ans[(*returnSize)++] = root->right;
        }
        return NULL;
    }
    return root;
}