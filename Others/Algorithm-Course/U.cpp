#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 100 + 10;
ll v[maxn], ans[maxn];
ll maxd;
bool better(ll d)
{
    return v[d] < ans[d] || ans[d] == -1;
}
ll get_first(ll a, ll b)
{
    ll c = b / a;
    if (b % a)
        c++;
    return c ;
}
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
        if(better(d))
            memcpy(ans, v, sizeof(ll) * (d + 1));
        return true;
    }
    bool ok = false;
    from = max(from, get_first(aa, bb));
    for(ll i = from; ; i++)
    {
        if(bb * (maxd + 1 - d) <= i * aa)
            break;
        v[d] = i;
        ll b2 = bb * i;
        ll a2 = aa * i - bb;
        ll g = gcd(a2, b2);
        if(dfs(d + 1, i + 1, a2 / g, b2 / g))
            ok = true;
    }
    return ok;
}
int main()
{
    ll a, b;
    scanf("%lld%lld", &a, &b);
    ll g = gcd(a, b);
    a /= g;
    b /= g;
    for(maxd = 0; ; maxd++)
    {
        memset(ans, -1, sizeof(ans));
        if(dfs(0, get_first(a, b), a, b))
        {
            for(int i = 0; i <= maxd; i++)
                printf("%lld ", ans[i]);
            putchar('\n');
            break;
        }
    }
    return 0;
}

