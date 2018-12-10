#include<bits/stdc++.h>
using namespace std;
const int maxm = 2e3 + 10;
const int maxn = 2e5 + 10;
int l[maxm], r[maxm], b[maxn];
int a[maxn], belong[maxn];
int query(int x, int y)
{
    int res = 0;
    for(int i = x; i <= min(y, r[belong[x]]); i++)
        res = max(res, a[i]);
    if(belong[x] == belong[y])
        return res;
    for(int i = belong[x] + 1; i < belong[y]; i++)
        res = max(res, b[i]);
    for(int i = l[belong[y]]; i <= y; i++)
        res = max(res, a[i]);
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m)
    {
        memset(b, 0, sizeof(b));
        int block = sqrt(n);
        int num = n / block;
        if(n % block)num++;
        for(int i = 1; i <= n; i++)
            belong[i] = (i - 1) / block + 1;
        for(int i = 1; i <= num; i++)
        {
            l[i] = (i - 1) * block + 1;
            r[i] = i * block;//处理每块的左右边界;
        }
        r[num] = n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[belong[i]] = max(b[belong[i]], a[i]);
        }
        while(m--)
        {
            char c; int x, y;
            cin >> c >> x >> y;
            if(c == 'Q')
                cout << query(x, y) << endl;
            else{
                a[x] = y;
                b[belong[x]] = max(b[belong[x]], y);
            }
        }
    }
}
