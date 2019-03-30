#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 10;
ll a[maxn], bit[maxn];
ll sum[maxn], ans;
void solve1(int n)
{
    for(int i = 1; i <= n; i++)
    {
        ans += (bit[i - 1] + mod - bit[n - i]) % mod * a[i];
        ans %= mod;
    }
    cout << ans << endl;
}
void solve2(int n)
{
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        sum[i] %= mod;
    }
    for(int i = 0; i <= n - 1; i++)
    {
        ll add = sum[n] + 2 * mod - sum[n - i - 1] - sum[i + 1];
        add %= mod;
        add *= bit[i];
        add %= mod;
        ans += add;
        ans %= mod;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    bit[0] = 1;
    for(int i = 1; i <= n; i++)
        bit[i] = bit[i - 1] * 2 % mod;
    solve1(n);
    //solve2(n);
    return 0;
}
