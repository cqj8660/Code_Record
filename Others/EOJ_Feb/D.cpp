#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define mp make_pair
#define eps 1e-6
#define mo %= MOD
using namespace std;
const int maxn = 2e5 + 10;
ll solve(ll t, ll k, ll m)
{
    vector<int> bit;
    while(t)
    {
        bit.push_back(t % k);
        t /= k;
    }
    int len = bit.size();
    ll res = 0, add = 1;
    if(len <= m)
        return 0;
    for(int i = len - 1; i > m; i--)
    {
        res = res * k + bit[i];
        add *= k;
    }
    res *= (k - 1);
    res += bit[m];
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        ll l, r, k, m;
        cin >> l >> r >> k >> m;
        ll b = solve(r, k, m);
        ll a = solve(l - 1, k, m);
        ll ans = b - a;
        cout << ans << endl;
    }
    return 0;
}
