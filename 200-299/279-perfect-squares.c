/* https://leetcode.cn/problems/perfect-squares/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int numSquares(int n);

int main(void){
    int n = 12;
    printf("%d\n", numSquares(n));
    return 0;
}

int numSquares(int n){
    int top = (int)ceil(sqrt(n));
    unsigned int f[top + 1][n + 1];
    memset(f, 0x3F, sizeof(int) * (n + 1));
    f[0][0] = 0;
    for (int i = 0; i < top; i++)
    {
        for (int t = 0; t <= n; t++)
        {
            if (t < (i + 1) * (i + 1))
            {
                f[i + 1][t] = f[i][t];
                continue;
            }
            f[i + 1][t] = MIN(f[i][t], f[i + 1][t - (i + 1) * (i + 1)] + 1);
        }
    }
    return f[top][n];
}