#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
ll a[maxn], p[maxn];
ll n, s;
ll solve(ll loc)
{
    ll res = 0;
    for(ll i = 0; i < n; i++)
        p[i] = (i + 1) * loc + a[i];
    sort(p, p + n);
    for(int i = 0; i < loc; i++)
    {
        res += p[i];
        if(res > s)
            return -1;
    }
    return res;
}
int main()
{
    scanf("%lld%lld", &n, &s);
    for(int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    int l = 0, r = n + 1;
    ll ans = 0;
    for(int i = 0; i < 30; i++)
    {
        int mid = (l + r) >> 1;
        int res = solve(mid);
        if(res > 0)
        {
            l = mid;
            ans = res;
        }
        else
            r = mid;
    }
    printf("%d %lld\n", l, ans);
    return 0;
}
