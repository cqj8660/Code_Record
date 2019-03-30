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
    int n;
    for(int i = 1; i <= 100; i++)
        dp[i][i] = dfs(i, i);
    while(cin >> n)
        cout << dp[n][n] << endl;
    return 0;
}
