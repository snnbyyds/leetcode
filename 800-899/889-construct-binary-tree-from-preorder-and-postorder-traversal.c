/* https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/ */

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void levelOrder(struct TreeNode *root);
struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize);

int main(void){
    int preorder[7] = {1, 2, 4, 5, 3, 6, 7};
    int postorder[7] = {4, 5, 2, 6, 7, 3, 1};
    levelOrder(constructFromPrePost(preorder, 7, postorder, 7));
    return 0;
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

struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize){
    if (preorderSize == 0 || postorderSize == 0)
    {
        return NULL;
    }
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;
    if (preorderSize > 1)
    {
        int idx = 0;
        while (idx < postorderSize && postorder[idx] != preorder[1])
        {
            idx++;
        }
        root->left = constructFromPrePost(preorder + 1, idx + 1, postorder, idx + 1);
        if (idx + 2 < postorderSize)
        {
            root->right = constructFromPrePost(preorder + idx + 2, preorderSize - idx - 2, postorder + idx + 1, postorderSize - idx - 2);
        }
    }
    return root;
}