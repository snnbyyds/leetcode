/* https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include<limits.h>

struct moves {
    int **from;
    int fromSize;
    int **to;
    int toSize;
};

int minimumMoves(int** grid, int gridSize, int* gridColSize);
void backtrack(int *ans, int **grid, int gridSize, int *gridColSize, struct moves *from_to, int *path, int top, bool *map);
int getdist(struct moves* from_to, int *path, int idx);
struct moves* getmoves(int** grid, int gridSize, int* gridColSize);

int main(void){
    int **grid = malloc(sizeof(int*) * 3);
    int grid0[3] = {1, 2, 2};
    int grid1[3] = {1, 1, 0};
    int grid2[3] = {0, 1, 1};
    grid[0] = grid0;
    grid[1] = grid1;
    grid[2] = grid2;
    int gridSize = 3;
    int gridColSize[3] = {3, 3, 3};
    printf("%d\n", minimumMoves(grid, gridSize, gridColSize));
    return 0;
}

int minimumMoves(int** grid, int gridSize, int* gridColSize){
    int ans = INT_MAX;
    struct moves *from_to = getmoves(grid, gridSize, gridColSize);
    assert(from_to->fromSize == from_to->toSize); // assert!
    int *path = malloc(sizeof(int) * from_to->fromSize); // use (idx, path[idx]) as a match
    bool *map = calloc(from_to->fromSize, sizeof(bool));
    backtrack(&ans, grid, gridSize, gridColSize, from_to, path, 0, map);
    return ans;
}

void backtrack(int *ans, int **grid, int gridSize, int *gridColSize, struct moves *from_to, int *path, int top, bool *map){
    if (top == from_to->fromSize)
    {
        int cur_ans = 0;
        for (int i = 0; i < top; i++)
        {
            cur_ans += getdist(from_to, path, i);
        }
        if (cur_ans < *ans)
        {
            *ans = cur_ans;
        }
        return;
    }
    for (int i = 0; i < from_to->fromSize; i++)
    {
        if (map[i])
        {
            continue;
        }
        path[top] = i;
        map[i] = true;
        backtrack(ans, grid, gridSize, gridColSize, from_to, path, top + 1, map);
        map[i] = false;
    }
}

int getdist(struct moves *from_to, int *path, int idx){
    return abs(from_to->from[idx][0] - from_to->to[path[idx]][0]) + abs(from_to->from[idx][1] - from_to->to[path[idx]][1]);
}

struct moves* getmoves(int** grid, int gridSize, int* gridColSize){
    struct moves* ret = malloc(sizeof(struct moves));
    ret->from = malloc(sizeof(int*) * gridSize * gridColSize[0]);
    ret->to = malloc(sizeof(int*) * gridSize * gridColSize[0]);
    int delta;
    int from_idx = 0, to_idx = 0;
    for (int r = 0; r < gridSize; r++)
    {
        for (int c = 0; c < gridColSize[r]; c++)
        {
            delta = grid[r][c] - 1;
            if (delta > 0)
            {
                int pos[2] = {r, c};
                for (int i = 0; i < delta; i++)
                {
                    ret->from[from_idx] = malloc(sizeof(pos));
                    memcpy(ret->from[from_idx++], pos, sizeof(pos));
                }
            }
            else if (delta < 0)
            {
                int pos[2] = {r, c};
                for (int i = 0; i < -delta; i++)
                {
                    ret->to[to_idx] = malloc(sizeof(pos));
                    memcpy(ret->to[to_idx++], pos, sizeof(pos));
                }
            }
        }
    }
    ret->fromSize = from_idx;
    ret->toSize = to_idx;
    return ret;
}