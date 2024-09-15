/* https://leetcode.cn/problems/ways-to-express-an-integer-as-sum-of-powers/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define M 1000000007

int numberOfWays(int n, int x);

int main(void){
    int n = 10;
    int x = 2;
    printf("%d\n", numberOfWays(n, x));
    return 0;
}

int numberOfWays(int n, int x){
    int top = (int)ceil(pow(n, 1.0 / (double)x));
    int f[top + 1][n + 1];
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    int k;
    for (int i = 0; i < top; i++)
    {
        for (int t = 0; t <= n; t++)
        {
            k = (int)pow(i + 1, x);
            if (t < k)
            {
                f[i + 1][t] = f[i][t];
                continue;
            }
            f[i + 1][t] = (f[i][t] % M + f[i][t - k] % M) % M;
        }
    }
    return f[top][n];
}