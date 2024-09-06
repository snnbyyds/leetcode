/* https://leetcode.cn/problems/UEcfPD/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int perfectMenu(int* materials, int materialsSize, int** cookbooks, int cookbooksSize, int* cookbooksColSize, int** attribute, int attributeSize, int* attributeColSize, int limit);
void backtrack(int* materials, int materialsSize, int** cookbooks, int cookbooksSize, int* cookbooksColSize, int** attribute, int attributeSize, int* attributeColSize, int limit, int *path, int top, int *ans, int cookbooksIdx);
bool valid(int* materials, int materialsSize, int** cookbooks, int cookbooksSize, int* cookbooksColSize, int** attribute, int attributeSize, int* attributeColSize, int limit, int *path, int top);

int main(void){
    int materials[5] = {3, 2, 4, 1, 2};
    int **cookbooks = malloc(sizeof(int*) * 3);
    int mat0[5] = {1, 1, 0, 1, 2};
    int mat1[5] = {2, 1, 4, 0, 0};
    int mat2[5] = {3, 2, 4, 1, 0};
    cookbooks[0] = mat0;
    cookbooks[1] = mat1;
    cookbooks[2] = mat2;
    int cookbooksColSize[3] = {5, 5, 5};
    int **attribute = malloc(sizeof(int*) * 3);
    int xy0[2] = {3, 2};
    int xy1[2] = {2, 4};
    int xy2[2] = {7, 6};
    attribute[0] = xy0;
    attribute[1] = xy1;
    attribute[2] = xy2;
    int attributeColSize[3] = {2, 2, 2};
    int limit = 5;
    printf("%d\n", perfectMenu(materials, 5, cookbooks, 3, cookbooksColSize, attribute, 3, attributeColSize, limit));
    return 0;
}

int perfectMenu(int* materials, int materialsSize, int** cookbooks, int cookbooksSize, int* cookbooksColSize, int** attribute, int attributeSize, int* attributeColSize, int limit){
    int ans = -1;
    int *path = malloc(sizeof(int) * cookbooksSize);
    backtrack(materials, materialsSize, cookbooks, cookbooksSize, cookbooksColSize, attribute, attributeSize, attributeColSize, limit, path, 0, &ans, 0);
    return ans;
}

void backtrack(int* materials, int materialsSize, int** cookbooks, int cookbooksSize, int* cookbooksColSize, int** attribute, int attributeSize, int* attributeColSize, int limit, int *path, int top, int *ans, int cookbooksIdx){
    if (cookbooksIdx == cookbooksSize)
    {
        if (valid(materials, materialsSize, cookbooks, cookbooksSize, cookbooksColSize, attribute, attributeSize, attributeColSize, limit, path, top))
        {
            int tastiness = 0;
            for (int i = 0; i < top; i++)
            {
                tastiness += attribute[path[i]][0];
            }
            *ans = MAX(*ans, tastiness);
        }
        return;
    }
    backtrack(materials, materialsSize, cookbooks, cookbooksSize, cookbooksColSize, attribute, attributeSize, attributeColSize, limit, path, top, ans, cookbooksIdx + 1);
    path[top] = cookbooksIdx;
    backtrack(materials, materialsSize, cookbooks, cookbooksSize, cookbooksColSize, attribute, attributeSize, attributeColSize, limit, path, top + 1, ans, cookbooksIdx + 1);
}

bool valid(int* materials, int materialsSize, int** cookbooks, int cookbooksSize, int* cookbooksColSize, int** attribute, int attributeSize, int* attributeColSize, int limit, int *path, int top){
    int sum_y = 0;
    for (int i = 0; i < top; i++)
    {
        sum_y += attribute[path[i]][1];
    }
    if (sum_y < limit)
    {
        return false;
    }
    int *needed_mat = calloc(cookbooksColSize[0], sizeof(int));
    for (int i = 0; i < cookbooksColSize[0]; i++)
    {
        for (int j = 0; j < top; j++)
        {
            needed_mat[i] += cookbooks[path[j]][i];
        }
        if (needed_mat[i] > materials[i])
        {
            return false;
        }
    }
    free(needed_mat);
    needed_mat = NULL;
    return true;
}