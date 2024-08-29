/* https://leetcode.cn/problems/flip-equivalent-binary-trees/ */

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
bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2);

int main(void){
    struct TreeNode *root1 = NULL;
    struct TreeNode *root2 = NULL;
    int empty = -1;
    int nums1[11] = {1, 2, 3, 4, 5, 6, -1, -1, -1, 7, 8};
    int nums2[13] = {1, 3, 2, -1, 6, 4, 5, -1, -1, -1, -1, 8, 7};
    create(nums1, 11, empty, &root1);
    create(nums2, 13, empty, &root2);
    printf("%d\n", flipEquiv(root1, root2) ? 1 : 0);
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

bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2){
    if (root1 == NULL || root2 == NULL)
    {
        return (root1 == root2);
    }
    if (root1->val != root2->val)
    {
        return false;
    }
    return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
}