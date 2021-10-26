#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 10;
int val[maxn], pre[maxn];
int main()
{
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);
    for(int i = 0; i < n; i++)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            val[l]++;
            val[r + 1]--;
        }
    int now = 0;
    for(int i = 1; i < maxn; i++)
    {
        now += val[i];
        if(now >= k)
            pre[i] = 1;
    }
    for(int i = 1; i < maxn; i++)
        pre[i] += pre[i - 1];
    while(q--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", pre[b] - pre[a - 1]);
    }
    return 0;
}
