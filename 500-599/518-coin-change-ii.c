/* https://leetcode.cn/problems/coin-change-ii/ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int change(int amount, int* coins, int coinsSize);

int main(void){
    int amount = 5;
    int coins[] = {1, 2, 5};
    printf("%d\n", change(amount, coins, 3));
    return 0;
}

int change(int amount, int* coins, int coinsSize){
    int f[coinsSize + 1][amount + 1];
    memset(f, 0, sizeof(int) * (amount + 1));
    f[0][0] = 1;
    for (int i = 0; i < coinsSize; i++)
    {
        for (int t = 0; t <= amount; t++)
        {
            if (t < coins[i])
            {
                f[i + 1][t] = f[i][t];
                continue;
            }
            f[i + 1][t] = f[i][t] + f[i + 1][t - coins[i]];
        }
    }
    return f[coinsSize][amount];
}