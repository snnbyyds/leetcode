/* https://leetcode.cn/problems/minimum-time-to-complete-trips/ */

#include<stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

long long minimumTime(int* time, int timeSize, int totalTrips);
long long mininarray(int *arr, int size);
long long gettrips(int *time, int timeSize, long long t);

int main(void){
    int time[3] = {1, 2, 3};
    int totalTrips = 5;
    printf("%lld\n", minimumTime(time, 3, totalTrips));
    return 0;
}

long long minimumTime(int* time, int timeSize, int totalTrips){
    long long mid;
    long long left = 1;
    long long right = (long long)totalTrips * mininarray(time, timeSize);
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (gettrips(time, timeSize, mid) < totalTrips)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}

long long mininarray(int *arr, int size){
    long long min = arr[0];
    for (int i = 0; i < size; i++)
    {
        min = MIN(min, arr[i]);
    }
    return min;
}

long long gettrips(int *time, int timeSize, long long t){
    long long trip = 0;
    for (int i = 0; i < timeSize; i++)
    {
        trip += t / time[i];
    }
    return trip;
}