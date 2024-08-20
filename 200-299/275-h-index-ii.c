/* https://leetcode.cn/problems/h-index-ii/ */

#include<stdio.h>

int hIndex(int* citations, int citationsSize);

int main(void){
    int citations[5] = {0, 1, 3, 5, 6};
    printf("%d\n", hIndex(citations, 5));
    return 0;
}

int hIndex(int* citations, int citationsSize){
    int left = 1;
    int right = citationsSize;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (citations[citationsSize - mid] >= mid)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return right;
}