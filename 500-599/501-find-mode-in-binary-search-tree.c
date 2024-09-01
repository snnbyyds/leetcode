/* https://leetcode.cn/problems/find-mode-in-binary-search-tree/ */

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
int* findMode(struct TreeNode* root, int* returnSize);
void dfs(struct TreeNode* root, int *arr, int *idx);

int main(void){
    struct TreeNode *root = NULL;
    int empty = -100001;
    int data[3] = {0, -100001, 0};
    create(data, 3, empty, &root);
    int returnSize;
    int *ans = findMode(root, &returnSize);
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

int* findMode(struct TreeNode* root, int* returnSize){
    int idx = 0;
    int arr[10001];
    int *ans = malloc(10001 * sizeof(int));
    dfs(root, arr, &idx);
    arr[idx] = 100001;
    *returnSize = 0;
    if (idx == 0)
    {
        return NULL;
    }
    int m = 1;
    int cnt = 1;
    for (int i = 0; i < idx; i++)
    {
        cnt += (arr[i] == arr[i + 1]);
        if (arr[i] != arr[i + 1])
        {
            if (cnt > m)
            {
                m = cnt;
                *returnSize = 1;
                ans[0] = arr[i];
            }
            else if (cnt == m)
            {
                (*returnSize)++;
                ans[*returnSize - 1] = arr[i];
            }
            cnt = 1;
        }
    }
    return ans;
}

void dfs(struct TreeNode* root, int *arr, int *idx){
    if (root == NULL)
    {
        return;
    }
    dfs(root->left, arr, idx);
    arr[(*idx)++] = root->val;
    dfs(root->right, arr, idx);
}