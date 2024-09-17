/* https://leetcode.cn/problems/best-team-with-no-conflicts/ */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

struct data
{
    int age;
    int score;
};

int bestTeamScore(int* scores, int scoresSize, int* ages, int agesSize);
void write_g(int *g, int *top, int num);
int cmp(const void *a, const void *b);

int main(void){
    int scores[] = {4, 5, 6, 5};
    int ages[] = {2, 1, 2, 1};
    printf("%d\n", bestTeamScore(scores, sizeof(scores) / sizeof(int), ages, sizeof(ages) / sizeof(int)));
    return 0;
}

int bestTeamScore(int* scores, int scoresSize, int* ages, int agesSize){
    struct data *datas = malloc(sizeof(struct data) * scoresSize);
    for (int i = 0; i < scoresSize; i++)
    {
        datas[i].age = ages[i];
        datas[i].score = scores[i];
    }
    // sort (priority: ages > scores)
    qsort(datas, scoresSize, sizeof(struct data), cmp);
    int *f = malloc(sizeof(int) * scoresSize);
    int ans = INT_MIN;
    for (int i = 0; i < scoresSize; i++)
    {
        f[i] = datas[i].score;
        for (int j = 0; j < i; j++)
        {
            if (datas[j].score <= datas[i].score)
            {
                if (f[i] < f[j] + datas[i].score)
                {
                    f[i] = f[j] + datas[i].score;
                }
            }
        }
        if (f[i] > ans)
        {
            ans = f[i];
        }
    }
    return ans;
}

int cmp(const void *a, const void *b){
    return ((struct data *)a)->age == ((struct data *)b)->age ? ((struct data *)a)->score - ((struct data *)b)->score : ((struct data *)a)->age - ((struct data *)b)->age;
}