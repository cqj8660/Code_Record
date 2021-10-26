#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 1e5 + 100;
ll ext[maxn];
int a, b, h, w, n;
ll dp[40][maxn];//dp[i][j]表示处理完前i位h最大为j时的w值
int solve(ll a, ll b)
{
    memset(dp, -1, sizeof(dp));
    dp[0][h] = w;
    for(int i = 1; i <= min(n, 35); i++)
    {
        for(int j = 1; j <= a; j++)
        {
            if(dp[i - 1][j] != -1)
            {
                ll temp = min(dp[i - 1][j] * ext[i], b);
                dp[i][j] = max(dp[i][j], temp);//乘到w上
                temp = min(j * ext[i], a);
                dp[i][temp] = max(dp[i][temp], dp[i - 1][j]);//乘到h上
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i <= min(n, 35); i++)
    {
        if(dp[i][a] >= b)
        {
            ans = i;
            break;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> h >> w >> n;
    for(int i = 1; i <= n; i++)
        cin >> ext[i];
    sort(ext + 1, ext + n + 1, greater<int>());
    int ans = INT_MAX;
    ans = min(ans, solve(a, b));
    ans = min(ans, solve(b, a));
    if(ans == INT_MAX)
        ans = -1;
    cout << ans << endl;
    return 0;
}

