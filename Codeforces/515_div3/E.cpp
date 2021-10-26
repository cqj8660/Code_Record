#include <bits/stdc++.h>
#define ll long long
const int maxn = 2e5 + 10;
using namespace std;
bitset<40> q(998244353);
int bit[maxn];
const int MOD = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    if(n > m)
    {
        a = a.substr(n - m);
        n = m;
    }
    if(m > n)
    {
        string t = "";
        for(int i = 0; i < m - n; i++)
            t += '0';
        a = t + a;
        n = m;
    }
    for(int i = 0; i < n; i++)
        bit[i] = b[i] -'0';
    for(int i = 1; i < n; i++)
        bit[i] += bit[i - 1];
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == '1')
            ans = ans * 2 + bit[i];
        else
            ans *= 2;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
