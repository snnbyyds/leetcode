/* https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree/ */

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
int** closestNodes(struct TreeNode* root, int* queries, int queriesSize, int* returnSize, int** returnColumnSizes);
void dfs(struct TreeNode* root, int* arr, int* idx);

int main(void){
    struct TreeNode *root = NULL;
    int empty = -1;
    int data[] = {6, 2, 13, 1, 4, 9, 15, -1, -1, -1, -1, -1, -1, 14};
    int dataSize = sizeof(data) / sizeof(int);
    create(data, dataSize, empty, &root);
    int returnSize;
    int *returnColumnSizes;
    int queries[3] = {2, 5, 16};
    int **ans = closestNodes(root, queries, 3, &returnSize, &returnColumnSizes);
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

int** closestNodes(struct TreeNode* root, int* queries, int queriesSize, int* returnSize, int** returnColumnSizes){
    int **ans = malloc(queriesSize * sizeof(int *));
    *returnColumnSizes = malloc(queriesSize * sizeof(int));
    int arr[100001];
    int idx = 0;
    dfs(root, arr, &idx);
    *returnSize = queriesSize;
    int left, mid, right;
    bool flag;
    for (int i = 0; i < queriesSize; i++)
    {
        (*returnColumnSizes)[i] = 2;
        left = 0;
        right = idx - 1;
        flag = false;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (queries[i] == arr[mid])
            {
                ans[i] = malloc(2 * sizeof(int));
                ans[i][0] = queries[i];
                ans[i][1] = queries[i];
                flag = true;
                break;
            }
            else if (queries[i] < arr[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (!flag)
        {
            ans[i] = malloc(2 * sizeof(int));
            ans[i][0] = right >= 0 ? arr[right] : -1;
            ans[i][1] = left < idx ? arr[left] : -1;
        }
    }
    return ans;
}

void dfs(struct TreeNode* root, int* arr, int* idx){
    if (root == NULL)
    {
        return;
    }
    dfs(root->left, arr, idx);
    arr[(*idx)++] = root->val;
    dfs(root->right, arr, idx);
}