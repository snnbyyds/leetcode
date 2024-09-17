/* https://leetcode.cn/problems/russian-doll-envelopes/ */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize);
int lower_bound(int* arr, int arrSize, int val);
int cmp(const void *a, const void *b);

int main(void){
    int envelopes0[] = {5, 4};
    int envelopes1[] = {6, 4};
    int envelopes2[] = {6, 7};
    int envelopes3[] = {2, 3};
    int *envelopes[4] = {envelopes0, envelopes1, envelopes2, envelopes3};
    int envelopesSize = 4;
    int envelopesColSize[] = {2, 2, 2, 2};
    printf("%d\n", maxEnvelopes(envelopes, envelopesSize, envelopesColSize));
    return 0;
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    qsort(envelopes, envelopesSize, sizeof(int*), cmp);
    int *g = malloc(sizeof(int) * envelopesSize);
    g[0] = envelopes[0][1];
    int gSize = 1;
    for (int i = 1; i < envelopesSize; i++)
    {
        if (envelopes[i][1] > g[gSize - 1])
        {
            g[gSize++] = envelopes[i][1];
        }
        else
        {
            g[lower_bound(g, gSize, envelopes[i][1])] = envelopes[i][1];
        }
    }
    return gSize;
}

int cmp(const void *a, const void *b){
    return (*(int**)a)[0] == (*(int**)b)[0] ? (*(int**)b)[1] - (*(int**)a)[1] : (*(int**)a)[0] - (*(int**)b)[0]; // !
}

int lower_bound(int* arr, int arrSize, int val){
    int left = 0, right = arrSize - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (val < arr[mid])
        {
            right = mid - 1;
        }
        else if (val > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return left;
}

// dp
/*
int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    qsort(envelopes, envelopesSize, sizeof(int*), cmp);
    int *f = malloc(sizeof(int) * envelopesSize);
    int ans = INT_MIN;
    for (int i = 0; i < envelopesSize; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
            {
                if (f[i] < f[j] + 1)
                {
                    f[i] = f[j] + 1;
                }
            }
        }
        if (ans < f[i])
        {
            ans = f[i];
        }
    }
    return ans;
}

int cmp(const void *a, const void *b){
    return (*(int**)a)[0] == (*(int**)b)[0] ? (*(int**)a)[1] - (*(int**)b)[1] : (*(int**)a)[0] - (*(int**)b)[0];
}
*/