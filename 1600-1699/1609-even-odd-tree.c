/* https://leetcode.cn/problems/even-odd-tree/ */

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
bool isEvenOddTree(struct TreeNode* root);

int main(void){
    int data[] = {1, 10, 4, 3, -1, 7, 9, 12, 8, 6, -1, -1, 2};
    int empty = -1;
    struct TreeNode *root = NULL;
    create(data, sizeof(data) / sizeof(int), empty, &root);
    printf("%d\n", isEvenOddTree(root) ? 1 : 0);
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

bool isEvenOddTree(struct TreeNode* root){
    struct TreeNode* queue[100001];
    int start;
    int head = 0;
    int rear = 0;
    queue[rear++] = root;
    int cnt = 0;
    while (head != rear)
    {
        start = head;
        head = rear;
        for (int i = start; i < head; i++)
        {
            if (queue[i]->val % 2 == cnt % 2)
            {
                return false;
            }
            if (i < head - 1)
            {
                if (cnt % 2 == 0 && queue[i]->val >= queue[i + 1]->val)
                {
                    return false;
                }
                else if (cnt % 2 != 0 && queue[i]->val <= queue[i + 1]->val)
                {
                    return false;
                }
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
    return true;
}