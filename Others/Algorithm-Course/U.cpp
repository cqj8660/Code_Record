#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 100 + 10;
ll v[maxn], ans[maxn];
ll maxd, best = INT_MAX;
ll gcd(ll a, ll b){
    if(b % a == 0)
        return a;
    return gcd(b, a % b);
}
bool dfs(ll d, ll from, ll aa, ll bb)
{
    if(d == maxd)
    {
        if(bb % aa)
            return false;
        v[d] = bb / aa;
        if(aa < best)
            memcpy(ans, v, sizeof(ll) * (d + 1));
        return true;
    }
    ll l = max(v[d - 1], bb / aa + (bb % aa == 0));
    for(ll i = l; ; i++)
    {
        if(aa * i >= bb * (maxd - d + 1)) break;
        v[d] = i;
        ll a2 = aa * i - bb, b2 = bb * i;
        
    }
}
int main()
{
    ll a, b;
    scanf("%lld%lld", &a, &b);
    for(maxd = 1; ; maxd++)
    {
        memset(ans, -1, sizeof(ans));
        if(dfs(1, b / a + (b % a == 0), a, b))
        {
            for(int i = 1; i <= maxd; i++)
                printf("%lld ", ans[i]);
            putchar('\n');
            break;
        }
    }
    return 0;
}

