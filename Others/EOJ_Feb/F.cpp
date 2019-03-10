#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define mp make_pair
#define eps 1e-6
#define mo %= MOD
using namespace std;
const int maxn = 2e6 + 10;
ll a[maxn];
ll sum[maxn], sum2[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        sum2[i] = sum2[i - 1] + a[i] * a[i];
    }
    ll mmin = -1;
    for(int i = 1; i <= n - m + 1; i++)
    {
        ll temp = m * 1LL * (sum2[i + m - 1] - sum2[i - 1]) - 1LL * (sum[i + m - 1] - sum[i - 1]) * 1LL*(sum[i + m - 1] - sum[i - 1]);
        if(mmin = -1)
            mmin = temp;
        else
            mmin = min(temp, mmin);
    }
    cout << mmin << endl;
    return 0;
}
