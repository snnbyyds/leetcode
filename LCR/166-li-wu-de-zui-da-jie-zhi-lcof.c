/* https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int jewelleryValue(int** frame, int frameSize, int* frameColSize);
// int dfs(int **frame, int r, int c, int cache[][200]);

int main(void){
    int **frame = malloc(sizeof(int*) * 3);
    int frame0[] = {1, 3, 1};
    int frame1[] = {1, 5, 1};
    int frame2[] = {4, 2, 1};
    frame[0] = frame0;
    frame[1] = frame1;
    frame[2] = frame2;
    int frameSize = 3;
    int frameColSize[3] = {3, 3, 3};
    printf("%d\n", jewelleryValue(frame, frameSize, frameColSize));
    return 0;
}

int jewelleryValue(int** frame, int frameSize, int* frameColSize){
    int f[200][200];
    for (int r = 0; r < frameSize; r++)
    {
        for (int c = 0; c < frameColSize[r]; c++)
        {
            f[r][c] = frame[r][c] + (int)fmax(c < 1 ? 0 : f[r][c - 1], r < 1 ? 0 : f[r - 1][c]);
        }
    }
    return f[frameSize - 1][frameColSize[frameSize - 1] - 1];
}

/*
int jewelleryValue(int** frame, int frameSize, int* frameColSize){
    int cache[200][200];
    memset(cache, 0, sizeof(int) * 40000);
    return dfs(frame, frameSize - 1, frameColSize[frameSize - 1] - 1, cache);
}

int dfs(int **frame, int r, int c, int cache[][200]){
    if (r < 0 || c < 0)
    {
        return 0;
    }
    if (r == 0 && c == 0)
    {
        return frame[r][c];
    }
    if (cache[r][c] != 0)
    {
        return cache[r][c];
    }
    cache[r][c] = frame[r][c] + (int)fmax(dfs(frame, r, c - 1, cache), dfs(frame, r - 1, c, cache));
    return cache[r][c];
}
*/