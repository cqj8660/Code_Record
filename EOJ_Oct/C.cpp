#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define mp make_pair
#define eps 1e-6
#define mo %= MOD
using namespace std;
const int maxn = 2e5 + 10;
const int MOD = 1e9 + 7;
ll r[maxn], b[maxn];
ll C;
map<pii, int> Q;
ll mul(ll a, ll b)
{
    ll ans = 0, step = a % MOD;
    while (b)
    {
        if (b & 1L) ans += step;
        if (ans >= MOD) ans %= MOD;
        step <<= 1L;
        if (step >= MOD) step %= MOD;
        b >>= 1L;
    }
    return ans % MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("in.txt", "r", stdin);
    ll n, k, q;
    cin >> n >> k >> q;
    C = n * n - k;
    C mo;
    while(k--)
    {
        int x, y;
        cin >> x >> y;
        Q[mp(x, y)] = 1;
        r[x]++, b[y]++;
    }
    for(int i = 1; i <= n; i++)
    {
        r[i] = n - r[i];
        b[i] = n - b[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += (r[i] * r[i]) % MOD;
        ans mo;
        ans += (b[i] * b[i]) % MOD;
        ans mo;
    }
    ans mo;
    ans = mul(ans, n - 2);
    ans += mul(2 * C, C) + C;
    ans mo;
    cout << ans << endl;
    while(q--)
    {
        int u, v;
        cin >> u >> v;
        if(Q[mp(u, v)] == 0)
        {
            Q[mp(u, v)] = 1;
            ans = (ans + 1 + MOD)- mul(4, C);
            ans mo;
            C--;
            C mo;
            ans = (ans + MOD) - (n - 2) * (2 * r[u] - 1) % MOD;
            ans mo;
            r[u]--;
            ans = (ans + MOD) - (n - 2) * (2 * b[v] - 1) % MOD;
            ans mo;
            b[v]--;
            cout << ans << endl;
        }
        else
        {
            Q[mp(u, v)] = 0;
            ans = ans + 3 + mul(4, C);
            ans mo;
            C++;
            C mo;
            ans = ans + (n - 2) * (2 * r[u] + 1) % MOD;
            ans mo;
            r[u]++;
            ans = ans + (n - 2) * (2 * b[v] + 1) % MOD;
            ans mo;
            b[v]++;
            ans mo;
            cout << ans << endl;
        }
    }
    return 0;
}
