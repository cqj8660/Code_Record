#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
const int maxn = 500 + 10;
int t[maxn], m[maxn], ans;
int dp[maxn][maxn];//dp[i][j]表示金钱为i时间为t时的最多个数
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, M, T;
    cin >> n >> M >> T;
    for(int i = 0; i < n; i++)
        cin >> m[i] >> t[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = M; j >= m[i]; j--)
        {
            for(int k = T; k >= t[i]; k--)
            {
                    dp[j][k] = max(dp[j - m[i]][k - t[i]] + 1, dp[j][k]);
                    ans = max(ans, dp[j][k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
