#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#define ll long long
using namespace std;
const int maxm = 2e3 + 10;
const int maxn = 2e5 + 10;
ll l[maxm], r[maxm], b[maxn];
ll a[maxn], belong[maxn], extra[maxn];
ll block;
ll query(ll x, ll y)
{
    ll res = 0;
    for(int i = x; i <= min(y, r[belong[x]]); i++)
        res += (a[i] + extra[belong[i]]);
    if(belong[x] == belong[y])
        return res;
    for(int i = belong[x] + 1; i < belong[y]; i++)
        res += b[i];
    for(int i = l[belong[y]]; i <= y; i++)
        res += (a[i] + extra[belong[i]]);
    return res;
}
void update(ll x, ll y, ll t)
{
    for(int i = x; i <= min(y, r[belong[x]]); i++)
        {
            a[i] += t;
            b[belong[i]] += t;
        }
    if(belong[x] == belong[y])
        return;
    for(int i = belong[x] + 1; i < belong[y]; i++)
    {
        b[i] += t * block;
        extra[i] += t;
    }
    for(int i = l[belong[y]]; i <= y; i++)
        {
            a[i] += t;
            b[belong[i]] += t;
        }

}
int main()
{
    ll n, m;
    //freopen("C:\\Users\\CQJ3360\\Desktop\\ss.txt", "r", stdin);
    while(~scanf("%lld%lld", &n, &m))
    {
        memset(b, 0, sizeof(b));
        memset(extra, 0, sizeof(extra));
        block = sqrt(n);
        ll num = n / block;
        if(n % block)
            num++;
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
            scanf("%lld", &a[i]);
            b[belong[i]] += a[i];
        }
        while(m--)
        {
            char c[10];
            ll x, y, t;
            scanf("%s%lld%lld", c, &x, &y);
            if(c[0] == 'Q')
                printf("%lld\n", query(x, y));
            else
            {
                scanf("%lld", &t);
                update(x, y, t);
            }
        }
    }
}
