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
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = -1;
        for( int j = 1; j <= x; j++)
        {
            dp[i][j] = -1;
            for(int t = 1; t <= min(k, i); t++)
                if(dp[i - t][j - 1] != -1)
                    dp[i][j] = max(dp[i][j], dp[i - t][j - 1] + a[i]);
        }
    }
    ll ans = -1;
    for(int i = n - k + 1; i <= n; i++)
        ans = max(ans, dp[i][x]);
    cout << ans << endl;
    return 0;
}
