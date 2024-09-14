/* https://leetcode.cn/problems/min-cost-climbing-stairs/ */

#include<stdio.h>

int minCostClimbingStairs(int* cost, int costSize);

int main(void){
    int cost[10] = {1, 100, 1, 1, 1, 100, 1, 1, 100 ,1};
    printf("%d\n", minCostClimbingStairs(cost, 10));
    return 0;
}

int minCostClimbingStairs(int* cost, int costSize){
    int f0 = 0;
    int f1 = 0;
    int new_f;
    for (int i = 2; i <= costSize; i++)
    {
        new_f = f0 + cost[i - 2] < f1 + cost[i - 1] ? f0 + cost[i - 2] : f1 + cost[i - 1];
        f0 = f1;
        f1 = new_f;
    }
    return f1;
}