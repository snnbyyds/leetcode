/* https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree/ */

#include<stdio.h>
#include<stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(int *nums, int numsSize, int empty, struct TreeNode **root);
struct TreeNode *initnode(int value);
long long kthLargestLevelSum(struct TreeNode* root, int k);
int getdepth(struct TreeNode *root);
int cmp(const void *a, const void *b);

int main(void){
    int data[] = {5, 8, 9, 2, 1, 3, 7, 4, 6};
    int empty = -1;
    struct TreeNode *root = NULL;
    create(data, sizeof(data) / sizeof(int), empty, &root);
    int k = 2;
    printf("%lld\n", kthLargestLevelSum(root, k));
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

long long kthLargestLevelSum(struct TreeNode* root, int k){
    struct TreeNode **queue = malloc(100001 * sizeof(struct TreeNode*));
    int depth = getdepth(root);
    long long *sumarr = malloc(depth * sizeof(long long));
    long long sum;
    int head = 0;
    int rear = 0;
    int start;
    queue[rear++] = root;
    int idx = 0;
    while (head != rear)
    {
        start = head;
        head = rear;
        sum = 0;
        for (int i = start; i < head; i++)
        {
            sum += (long long)(queue[i]->val);
            if (queue[i]->left != NULL)
            {
                queue[rear++] = queue[i]->left;
            }
            if (queue[i]->right != NULL)
            {
                queue[rear++] = queue[i]->right;
            }
        }
        sumarr[idx++] = sum;
    }
    qsort(sumarr, depth, sizeof(long long), cmp);
    return depth < k ? -1 : sumarr[depth - k];
}

int getdepth(struct TreeNode *root){
    if (root == NULL)
    {
        return 0;
    }
    int l_depth = getdepth(root->left);
    int r_depth = getdepth(root->right);
    return MAX(l_depth, r_depth) + 1;
}

int cmp(const void *a, const void *b) {
    long long delta = *(long long *)a - *(long long *)b;
    return delta < 0 ? -1 : 1;
}