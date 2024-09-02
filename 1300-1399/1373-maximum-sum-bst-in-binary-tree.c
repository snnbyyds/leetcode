/* https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeStat {
    int max;
    int min;
    int sum;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
int maxSumBST(struct TreeNode* root);
struct TreeStat dfs(struct TreeNode *root, int *ans);

int main(void){
    int empty = 40001;
    int data[] = {1, 4, 3, 2, 4, 2, 5, 40001, 40001, 40001, 40001, 40001, 40001, 4, 6};
    int dataSize = sizeof(data) / sizeof(int);
    struct TreeNode *root = NULL;
    create(data, dataSize, empty, &root);
    printf("%d\n", maxSumBST(root));
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

int maxSumBST(struct TreeNode* root){
    int ans = 0;
    dfs(root, &ans);
    return ans;
}

struct TreeStat dfs(struct TreeNode *root, int *ans){
    struct TreeStat stat;
    if (root == NULL)
    {
        stat.max = INT_MIN;
        stat.min = INT_MAX;
        stat.sum = 0;
        return stat;
    }
    struct TreeStat l_stat = dfs(root->left, ans);
    struct TreeStat r_stat = dfs(root->right, ans);
    if (root->val <= l_stat.max || root->val >= r_stat.min)
    {
        stat.max = INT_MAX;
        stat.min = INT_MIN;
        stat.sum = 0;
        return stat;
    }
    int s = root->val + l_stat.sum + r_stat.sum;
    stat.sum = s;
    stat.min = MIN(l_stat.min, root->val);
    stat.max = MAX(r_stat.max, root->val);
    *ans = MAX(s, *ans);
    return stat;
}