/* https://leetcode.cn/problems/range-sum-of-bst/ */

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
int rangeSumBST(struct TreeNode* root, int low, int high);
void getsum(struct TreeNode* root, int low, int high, int *sum);

int main(void){
    int empty = -1;
    int data[7] = {10, 5, 15, 3, 7, -1, 18};
    struct TreeNode *root = NULL;
    create(data, 7, empty, &root);
    int low = 7;
    int high = 15;
    printf("%d\n", rangeSumBST(root, low, high));
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

int rangeSumBST(struct TreeNode* root, int low, int high){
    int sum = 0;
    getsum(root, low, high, &sum);
    return sum;
}

void getsum(struct TreeNode* root, int low, int high, int *sum){
    if (root == NULL)
    {
        return;
    }
    if (root->val >= low && root->val <= high)
    {
        *sum += root->val;
        getsum(root->right, low, high, sum);
        getsum(root->left, low, high, sum);
    }
    else if (root->val < low)
    {
        getsum(root->right, low, high, sum);
    }
    else
    {
        getsum(root->left, low, high, sum);
    }
}