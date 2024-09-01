/* https://leetcode.cn/problems/kth-smallest-element-in-a-bst/ */

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
int kthSmallest(struct TreeNode* root, int k);
void dfs(struct TreeNode* root, int *ans, int *cnt, int k);

int main(void){
    struct TreeNode *root = NULL;
    int empty = -1;
    int data[8] = {5, 3, 6, 2, 4, -1, -1, 1};
    create(data, 8, empty, &root);
    int k = 3;
    printf("%d\n", kthSmallest(root, k));
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

int kthSmallest(struct TreeNode* root, int k){
    int cnt = 0;
    int ans;
    dfs(root, &ans, &cnt, k);
    return ans;
}

void dfs(struct TreeNode* root, int *ans, int *cnt, int k){
    if (root == NULL)
    {
        return;
    }
    dfs(root->left, ans, cnt, k);
    (*cnt)++;
    if (*cnt == k)
    {
        *ans = root->val;
        return;
    }
    dfs(root->right, ans, cnt, k);
}