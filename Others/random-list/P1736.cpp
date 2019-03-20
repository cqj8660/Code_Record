#include <bits/stdc++.h>
using namespace std;
const int maxn = 2500 + 10;
int g[maxn][maxn];
int dp[maxn][maxn], row[maxn][maxn], col[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
//    freopen("/Users/vector/Downloads/testdata.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if(g[i][j])
                ans = 1;
        }
    for(int i = 0; i < n; i++)
    {
        if(g[i][0])
            dp[i][0] = 1;
        else
            if(i > 0)
            {
                col[i][0] = col[i - 1][0] + 1;
                row[i][0] = 1;
            }
    }
    for(int i = 0; i < m; i++)
    {
        if(g[0][i])
            dp[0][i] = 1;
        else
            if(i > 0)
            {
                row[0][i] = row[0][i - 1] + 1;
                col[0][i] = 1;
            }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(g[i][j])
            {
                dp[i][j] = min(min(dp[i - 1][j - 1], col[i - 1][j]), row[i][j - 1]) + 1;
//                int q = dp[i][j];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                col[i][j] = col[i - 1][j] + 1;
                row[i][j] = row[i][j - 1] + 1;
            }
        }
    }
    memset(dp, 0, sizeof(dp));
    memset(col, 0, sizeof(col));
    memset(row, 0, sizeof(row));
    for(int i = m - 1; i >= 0; i--)
    {
        if(g[0][i])
            dp[0][i] = 1;
        else
            if(i < m - 1)
            {
                row[0][i] = row[0][i + 1] + 1;
                col[0][i] = 1;
            }
    }
    for(int i = 0; i < n; i++)
    {
        if(g[i][0])
            dp[i][0] = 1;
        else
            if(i > 0)
            {
                col[i][0] = col[i - 1][0] + 1;
                row[i][0] = 1;
            }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = m - 1; j >= 0; j--)
        {
            if(g[i][j])
            {
                dp[i][j] = min(min(dp[i - 1][j + 1], col[i - 1][j]), row[i][j + 1]) + 1;
                //int q = dp[i][j];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                col[i][j] = col[i - 1][j] + 1;
                row[i][j] = row[i][j + 1] + 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

