/* https://leetcode.cn/problems/find-the-longest-valid-obstacle-course-at-each-position/ */

#include<stdio.h>
#include<stdlib.h>

int* longestObstacleCourseAtEachPosition(int* obstacles, int obstaclesSize, int* returnSize);
void write_g(int *g, int *top, int *obstacles, int i, int *ans);

int main(void){
    int returnSize;
    // int obstacles[] = {3, 1, 5, 6, 4, 2};
    int obstacles[] = {1, 2, 3, 2};
    int *ans = longestObstacleCourseAtEachPosition(obstacles, sizeof(obstacles) / sizeof(int), &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d\t", ans[i]);
    }
    printf("\n");
    free(ans);
    return 0;
}

int* longestObstacleCourseAtEachPosition(int* obstacles, int obstaclesSize, int* returnSize){
    int *g = malloc(sizeof(int) * (obstaclesSize + 1));
    int *ans = calloc(obstaclesSize, sizeof(int));
    *returnSize = obstaclesSize;
    int top = 1;
    g[0] = obstacles[0];
    ans[0] = 1;
    for (int i = 1; i < obstaclesSize; i++)
    {
        write_g(g, &top, obstacles, i, ans);
    }
    free(g);
    return ans;
}

void write_g(int *g, int *top, int *obstacles, int i, int *ans){
    if (obstacles[i] >= g[*top - 1])
    {
        g[(*top)++] = obstacles[i];
        ans[i] = *top;
        return;
    }
    int left = 0;
    int right = *top - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (g[mid] <= obstacles[i])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    g[left] = obstacles[i];
    ans[i] = left + 1;
}

// dp
/*
int* longestObstacleCourseAtEachPosition(int* obstacles, int obstaclesSize, int* returnSize){
    int *f = malloc(sizeof(int) * obstaclesSize);
    *returnSize = obstaclesSize;
    for (int i = 0; i < obstaclesSize; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (obstacles[j] <= obstacles[i])
            {
                if (f[i] < f[j] + 1)
                {
                    f[i] = f[j] + 1;
                }
            }
        }
    }
    return f;
}
*/