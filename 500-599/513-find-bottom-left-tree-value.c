/* https://leetcode.cn/problems/find-bottom-left-tree-value/ */

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
int findBottomLeftValue(struct TreeNode* root);

int main(void){
    int empty = -1;
    int data[] = {1, 2, 3, 4, -1, 5, 6, -1, -1, 7};
    struct TreeNode *root = NULL;
    create(data, sizeof(data) / sizeof(int), empty, &root);
    printf("%d\n", findBottomLeftValue(root));
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

int findBottomLeftValue(struct TreeNode* root){
    struct TreeNode **queue = malloc(10001 * sizeof(struct TreeNode *));
    int start;
    int head = 0;
    int rear = 0;
    queue[rear++] = root;
    while (head != rear)
    {
        start = head;
        head = rear;
        for (int i = start; i < head; i++)
        {
            if (queue[i]->right != NULL)
            {
                queue[rear++] = queue[i]->right;
            }
            if (queue[i]->left != NULL)
            {
                queue[rear++] = queue[i]->left;
            }
        }
    }
    return queue[rear - 1]->val;
}