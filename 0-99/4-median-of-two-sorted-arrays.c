/* https://leetcode.cn/problems/median-of-two-sorted-arrays */

#include <stdio.h>
#include <stdlib.h>

int* mergesort(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // init merged array
    int *merged = malloc((nums1Size + nums2Size) * sizeof(int));

    int i = 0;
    int j = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
            merged[i + j] = nums1[i];
            i++;
        }
        else
        {
            merged[i + j] = nums2[j];
            j++;
        }
    }
    if (i != nums1Size) {
        while (i < nums1Size) {
            merged[i + j] = nums1[i];
            i++;
        }
    }
    else if (j != nums2Size) {
        while (j < nums2Size) {
            merged[i + j] = nums2[j];
            j++;
        }
    }

    return merged;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *merged = mergesort(nums1, nums1Size, nums2, nums2Size);
    double mid;
    if ((nums1Size + nums2Size) % 2 == 0) {
        mid = 0.5 * (merged[(nums1Size + nums2Size) / 2 - 1] + merged[(nums1Size + nums2Size) / 2]);
    }
    else
    {
        mid = merged[(nums1Size + nums2Size) / 2];
    }
    free(merged);
    merged = NULL;
    return mid;
}

int main(void) {
    int nums1[2] = {1, 2};
    int nums2[1] = {2};
    printf("%lf\n", findMedianSortedArrays(nums1, 2, nums2, 1));
    return 0;
}