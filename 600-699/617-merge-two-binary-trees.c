/* https://leetcode.cn/problems/merge-two-binary-trees/ */

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
void levelOrder(struct TreeNode *root);
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2);

int main(void){
    int data1[4] = {1, 3, 2, 5};
    int data2[7] = {2, 1, 3, -10001, 4, -10001, 7};
    int empty = -10001;
    struct TreeNode *root1 = NULL;
    struct TreeNode *root2 = NULL;
    create(data1, 4, empty, &root1);
    create(data2, 7, empty, &root2);
    struct TreeNode *root3 = mergeTrees(root1, root2);
    levelOrder(root3);
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

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
    if (root1 == NULL)
    {
        return root2;
    }
    if (root2 == NULL)
    {
        return root1;
    }
    struct TreeNode *m = malloc(sizeof(struct TreeNode));
    m->val = root1->val + root2->val;
    m->left = mergeTrees(root1->left, root2->left);
    m->right = mergeTrees(root1->right, root2->right);
    return m;
}