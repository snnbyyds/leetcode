/* https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree/ */

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
struct TreeNode* reverseOddLevels(struct TreeNode* root);

int main(void){
    struct TreeNode *root = NULL;
    int data[] = {2, 3, 5, 8, 13, 21, 34};
    int empty = -1;
    create(data, sizeof(data) / sizeof(int), empty, &root);
    levelOrder(root);
    struct TreeNode *ans = reverseOddLevels(root);
    levelOrder(ans);
    return 0;
}

void create(int *nums, int numsSize, int empty, struct TreeNode **root){
    if (numsSize == 0 || nums[0] == empty)
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

struct TreeNode* reverseOddLevels(struct TreeNode* root){
    struct TreeNode* queue[16384];
    int start;
    int head = 0;
    int rear = 0;
    queue[rear++] = root;
    int cnt = 0;
    int tmp;
    while (head != rear)
    {
        start = head;
        head = rear;
        for (int i = start; i < head; i++)
        {
            if (cnt % 2 != 0 && i < (start + head) / 2)
            {
                tmp = queue[i]->val;
                queue[i]->val = queue[head - 1 - i + start]->val;
                queue[head - 1 - i + start]->val = tmp;
            }
            if (queue[i]->left != NULL)
            {
                queue[rear++] = queue[i]->left;
            }
            if (queue[i]->right != NULL)
            {
                queue[rear++] = queue[i]->right;
            }
        }
        cnt++;
    }
    return root;
}