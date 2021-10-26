#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define eps 1e-6
using namespace std;
const int maxn = 2e5 + 10;
const int MOD = 1e9 + 7;
int l[maxn], r[maxn];
ll fac[maxn];
ll quickmod(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res *= a;
        a = a * a % MOD;
        b >>= 1;
        res %= MOD;
    }
    return res;
}
ll C(ll a, ll b)
{
    if(b > a || b < 0) return 0;
    ll s1 = fac[a], s2 = fac[a - b] * fac[b] % MOD;
    return s1 * quickmod(s2, MOD - 2) % MOD;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int len = s.length();
    for(int i = 1; i < len; i++)
    {
        if(s[i - 1] == '(')
            l[i]++;
        l[i] += l[i - 1];
    }
    for(int i = len - 2; i >= 0; i--)
    {
        if(s[i + 1] == ')')
            r[i]++;
        r[i] += r[i + 1];
    }
    fac[0] = 1;
    fac[1] = 1;
    for(int i = 2; i <= len; i++)
        fac[i] = fac[i - 1] * i % MOD;
    ll ans = 0;
    for(int i = 0; i < len; i++)
    {
        if(s[i] == ')') continue;
        ans += C(l[i] + r[i], r[i] - 1);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
