/* https://leetcode.cn/problems/maximum-depth-of-binary-tree/ */

#include<stdio.h>
#include<stdlib.h>
#include<libqueue/queue.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int idx = 0;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root);
void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);

int main(void){
    int empty = -101; // Use -101 to represent NULL
    int data[10] = {3, 9, 20, -101, -101, 15, 7, 9, -101, 10};
    struct TreeNode *root = NULL;
    create(data, 10, empty, &root);
    printf("%d\n", maxDepth(root));
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

int maxDepth(struct TreeNode* root){
    if (root == NULL)
    {
        return 0;
    }
    int l_depth = maxDepth(root->left);
    int r_depth = maxDepth(root->right);
    return MAX(l_depth, r_depth) + 1;
}