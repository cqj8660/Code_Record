#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e3 + 10;
using namespace std;
int a[maxn];
ll dp[maxn][maxn];//dp[i][j]表示在最后一个选中的是i且取了j个的最大beauty值
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= x; j++)
            dp[i][j] = -1e18;
    dp[0][0] = 0;
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= n; j++)
            for(int t = 1; t <= min(k, j); t++)
                    dp[j][i] = max(dp[j][i], dp[j - t][i - 1] + a[j]);
    ll ans = -1;
    for(int i = n - k + 1; i <= n; i++)
        ans = max(ans, dp[i][x]);
    cout << ans << endl;
    return 0;
}
