/* https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/ */

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void levelOrder(struct TreeNode *root);
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize);

int main(void){
    int preorder[5] = {3, 9, 20, 15, 7};
    int inorder[5] = {9, 3, 15, 20, 7};
    struct TreeNode* root = buildTree(preorder, 5, inorder, 5);
    levelOrder(root);
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

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorderSize == 0 || inorderSize == 0)
    {
        return NULL;
    }
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int idx = 0;
    while (idx < inorderSize && inorder[idx] != preorder[0])
    {
        idx++;
    }
    root->left = buildTree(preorder + 1, preorderSize - 1, inorder, idx);
    root->right = buildTree(preorder + idx + 1, preorderSize - idx - 1, inorder + idx + 1, inorderSize - idx - 1);
    return root;
}