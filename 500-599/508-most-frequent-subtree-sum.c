/* https://leetcode.cn/problems/most-frequent-subtree-sum/ */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
int cmp(const void *a, const void *b);
int dfs(struct TreeNode *root, int *ans, int *idx);
int* findFrequentTreeSum(struct TreeNode* root, int* returnSize);

int main(void){
    struct TreeNode *root = NULL;
    int data[3] = {5, 2, -3};
    int empty = -100001;
    int returnSize;
    create(data, 3, empty, &root);
    int *ans = findFrequentTreeSum(root, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
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

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int dfs(struct TreeNode *root, int *ans, int *idx){
    if (root == NULL)
    {
        return 0;
    }
    int s = root->val + dfs(root->left, ans, idx) + dfs(root->right, ans, idx);
    ans[*idx] = s;
    (*idx)++;
    return s;
}

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize){
    int sums[10001] = {INT_MAX};
    int *ans = malloc(10001 * sizeof(int));
    int idx = 0;
    dfs(root, sums, &idx);
    qsort(sums, idx, sizeof(int), cmp);
    sums[idx] = 100000;
    int max = 1;
    int cur = 1;
    int k = 0;
    for (int i = 0; i < idx; i++)
    {
        if (sums[i] == sums[i + 1])
        {
            cur++;
        }
        else
        {
            if (cur == max)
            {
                ans[k++] = sums[i];
            }
            else if (cur > max)
            {
                max = cur;
                k = 0;
                ans[k++] = sums[i];
            }
            cur = 1;
        }
    }
    *returnSize = k;
    return ans;
}