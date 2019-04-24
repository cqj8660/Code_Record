#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e3;
ll dp[maxn][maxn];
ll dfs(int n, int m)//整数n使用不大于m的整数进行拆分
{
    if(dp[n][m])
        return dp[n][m];
    if(n == 1 || m == 1)
        return dp[n][m] = 1;
    if(n > m)
        return dp[n][m] = dfs(n, m - 1) + dfs(n - m, m);
    else if(n == m)
        return dp[n][m] = dfs(n, m - 1) + 1;
    else
        return dp[n][n] = dfs(n, n);
}
int main()
{
    int n = 100;
//    for(int i = 1; i <= 100; i++)
//        dp[i][i] = dfs(i, i);
    for(int i = 1; i <= n; i++)
        dp[i][1] = dp[1][i] = 1;
    for(int i = 2; i <= n; i++)
        for(int j = 2; j <= i; j++)
        {
            if(i == j)
                dp[i][j] = dp[i][j - 1] + 1;
            else if((i - j) > j)
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            else
                dp[i][j] = dp[i][j - 1] + dp[i - j][i - j];
        }
    while(cin >> n)
        cout << dp[n][n] << endl;
    return 0;
}
