/* https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/ */

#include<stdio.h>
#include<stdlib.h>

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize);
int cmp(const void *a, const void *b);
int getlowbound();

int main(void){
    int spells[3] = {3, 1, 2};
    int potions[3] = {8, 5, 8};
    long long success = 16;
    int returnSize;
    int *ans = successfulPairs(spells, 3, potions, 3, success, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    free(ans);
    return 0;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize){
    qsort(potions, potionsSize, sizeof(int), cmp);
    int *ans = malloc(sizeof(int) * spellsSize);
    int left, right, mid;
    for (int s = 0; s < spellsSize; s++)
    {
        left = 0;
        right = potionsSize - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if ((long long)spells[s] * potions[mid] < success)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        ans[s] = potionsSize - left;
    }
    *returnSize = spellsSize;
    return ans;
}

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}