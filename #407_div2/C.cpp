#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e5 + 10;
using namespace std;
int n;
ll dp[maxn], a[maxn];
ll pl[maxn], mi[maxn];
ll cal(ll *p, int len)
{
    ll res = INT_MIN, temp = 0;
    for(int i = 0; i < len; i++)
    {
        temp += p[i];
        res = max(res, temp);
        if(temp < 0)
            temp = 0;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++)
    {
        pl[i] = abs(a[i] - a[i + 1]);
        if(i % 2) pl[i] *= -1;
    }
    for(int i = 1; i < n - 1; i++)
    {
        mi[i - 1] = abs(a[i] - a[i + 1]);
        if(i % 2 == 0) mi[i - 1] *= -1;
    }
    ll a = cal(pl, n - 1);
    ll b = cal(mi, n - 2);
    cout << max(a, b) << endl;
    return 0;
}
