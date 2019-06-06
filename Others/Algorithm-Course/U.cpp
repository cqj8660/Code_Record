#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e8 + 10;
int v[maxn], ans[maxn];
int maxd;
bool better(int d)
{
    for(int i = d; i >= 0; i--)
        if(v[i] != ans[i])
        {
            return ans[i] == -1 || v[i] < ans[i];
        }
    return false;
}
int get_first(ll a, ll b)
{
    for(ll i = 2; ; i++)
    {
        if(b <= a * i)
            return i;
    }
    ll l = 1, r = 1e16;
    ll res;
    for(int i = 0; i < 100; i++)
    {
        int mid = (l + r) >> 1;
        if(b <= a * mid)
        {
            res = mid;
            l = mid;
        }
        else
            r = mid;
    }
    return res;
}
bool dfs(int d, int from, ll aa, ll bb)
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
    for(int i = from; ; i++)
    {
        if(bb * (maxd + 1 - d) <= i * aa)
            break;
        v[d] = i;
        ll b2 = bb * i;
        ll a2 = aa * i - bb;
        ll g = __gcd(a2, b2);
        if(dfs(d + 1, i + 1, a2 / g, b2 / g))
            ok = true;
    }
    return ok;
}
int main()
{
    int ok = 0;
    int a, b;
    cin >> a >> b;
    for(maxd = 0; ; maxd++)
    {
        memset(ans, -1, sizeof(ans));
        if(dfs(0, get_first(a, b), a, b))
        {
            ok = 1;
            break;
        }
    }
    for(int i = 0; i <= maxd; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}

