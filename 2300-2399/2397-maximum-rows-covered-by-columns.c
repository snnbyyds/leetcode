/* https://leetcode.cn/problems/maximum-rows-covered-by-columns/ */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maximumRows(int** matrix, int matrixSize, int* matrixColSize, int numSelect);
void backtrack(int *ans, int** matrix, int matrixSize, int* matrixColSize, int numSelect, int *path, int top, int startidx);
int covered(int** matrix, int matrixSize, int* matrixColSize, int *path, int top);

int main(void){
    int **matrix = malloc(sizeof(int*) * 4);
    int matrix0[3] = {0, 0, 0};
    int matrix1[3] = {1, 0, 1};
    int matrix2[3] = {0, 1, 1};
    int matrix3[3] = {0, 0, 1};
    matrix[0] = matrix0;
    matrix[1] = matrix1;
    matrix[2] = matrix2;
    matrix[3] = matrix3;
    int matrixSize = 4;
    int matrixColSize[4] = {3, 3, 3, 3};
    int numSelect = 2;
    printf("%d\n", maximumRows(matrix, matrixSize, matrixColSize, numSelect));
    return 0;
}

int maximumRows(int** matrix, int matrixSize, int* matrixColSize, int numSelect){
    int ans = -1;
    int *path = malloc(sizeof(int) * (numSelect + 1));
    backtrack(&ans, matrix, matrixSize, matrixColSize, numSelect, path, 0, 0);
    return ans;
}

void backtrack(int *ans, int** matrix, int matrixSize, int* matrixColSize, int numSelect, int *path, int top, int startidx){
    if (top == numSelect)
    {
        int is_covered = covered(matrix, matrixSize, matrixColSize, path, top);
        *ans = MAX(*ans, is_covered);
        return;
    }
    for (int i = startidx; i < matrixColSize[0] - (numSelect - top) + 1; i++)
    {
        path[top++] = i;
        backtrack(ans, matrix, matrixSize, matrixColSize, numSelect, path, top, i + 1);
        top--;
    }
}

int covered(int** matrix, int matrixSize, int* matrixColSize, int *path, int top){
    int covered = 0;
    bool covered_flag;
    bool map[matrixColSize[0]];
    memset(map, 0, matrixColSize[0] * sizeof(bool));
    // bool *map = calloc(matrixColSize[0], sizeof(bool));
    for (int i = 0; i < top; i++)
    {
        map[path[i]] = true;
    }
    for (int i = 0; i < matrixSize; i++)
    {
        covered_flag = true;
        for (int j = 0; j < matrixColSize[i]; j++)
        {
            if (matrix[i][j] == 1 && map[j] == false)
            {
                covered_flag = false;
                break;
            }
        }
        if (covered_flag)
        {
            covered++;
        }
    }
    return covered;
}