//
//  k-merge.cpp
//  hellomac
//
//  Created by Qjchen on 2019/3/6.
//  Copyright © 2019年 Qjchen. All rights reserved.
//
#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn], tmp[maxn];
void merge(int * a, int l, int r, int * tmp, int k)
{
//    printf("%d -> %d   %d\n", l, r, k);
    int len = (r - l + 1) / k, t = 0;
    vector<int> beg, end;
    for(int i = 0; i < k; i++)
        beg.push_back(l + i * len);
    for(int i = 0; i < k - 1; i++)
        end.push_back(l + (i + 1) * len - 1);
    end.push_back(r);
    while(t < r - l + 1)
    {
        int mmin = INT_MAX, loc = -1;
        for(int i = 0; i < k; i++)
        {
            if(beg[i] <= end[i])
                if(a[beg[i]] < mmin)
                {
                    mmin = a[beg[i]];
                    loc = i;
                }
        }
        tmp[t++] = a[beg[loc]++];
    }
    for(int i = 0; i < r - l + 1; i++)
        a[l + i] = tmp[i];
}
void Mergesort(int * a, int l, int r, int tmp[], int k)
{
    if(r - l + 1 <= k)
    {
        merge(a, l, r, tmp, r - l + 1);
    }
    else if(l < r)
        {
            int len = (r - l + 1) / k;
            for(int i = 0; i < k; i++)
            {
                if(i < k - 1)
                    Mergesort(a, l + i * len, l + (i + 1) * len - 1, tmp, k);
    //                printf("%d %d\n", l + i * len, l + (i + 1) * len - 1);
                else
                    Mergesort(a, l + i * len, r, tmp, k);
    //                printf("%d %d\n", l + i * len, r);
            }
            merge(a, l, r, tmp, k);
        }
}
int main()
{
    freopen("/Users/vector/Documents/Algorithm-design/lab0/k-merge/data1m.txt", "r", stdin);
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    struct  timeval start;
    struct  timeval end;
    unsigned long diff;
    gettimeofday(&start,NULL);
    Mergesort(a, 0, n - 1, tmp, 15);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    printf("Done!\nTime Cost: %.6f\n", diff * 1.0 / 1000000);
    return 0;
}
