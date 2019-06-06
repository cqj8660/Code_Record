#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 10;
int val[maxn], pre[maxn];
int m, b;
ll solve(ll a, ll b)
{
    ll res = (1 + a) * a / 2 * (b + 1);
    res += (1 + b) * b / 2 * (1 + a);
    return res;
}
int f(int x)
{
    return -x / m + b;
}
int main()
{
    cin >> m >> b;
    ll ans = 0;
    for(int i = 0; i <= b * m; i++)
    {
        if(i % m == 0)
            ans = max(ans, solve(i, f(i)));
    }
    cout << ans << endl;
    return 0;
}
