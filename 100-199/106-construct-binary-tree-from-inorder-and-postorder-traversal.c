/* https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ */

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void levelOrder(struct TreeNode *root);
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize);

int main(void){
    int inorder[5] = {9, 3, 15, 20, 7};
    int postorder[5] = {9, 15, 7, 20, 3};
    levelOrder(buildTree(inorder, 5, postorder, 5));
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

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if (inorderSize == 0 || postorderSize == 0)
    {
        return NULL;
    }
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];
    int idx = 0;
    while (idx < inorderSize && inorder[idx] != postorder[postorderSize - 1])
    {
        idx++;
    }
    root->left = buildTree(inorder, idx, postorder, idx);
    root->right = buildTree(inorder + idx + 1, inorderSize - idx, postorder + idx, postorderSize - idx - 1);
    return root;
}