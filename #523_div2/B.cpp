#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
ll a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    ll mmax = -1, sum = 0, ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        mmax = max(mmax, a[i]);
    }
    sort(a + 1, a + 1 + n);
    ll idx = 1;
    for(int i = 1; i <= n; i++)
    {
        if(i == n)
        {
            if(a[i] != 1)
                ans += idx - 1;
            continue;
        }
        if(a[i] == 1)
        {
            if(i == 1)
                idx++;
            continue;
        }
        else
            ans += a[i] - 1;
        if(a[i] >= idx && idx < mmax)
            idx++;
    }
    cout << ans << endl;
    return 0;
}
