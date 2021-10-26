#include <bits/stdc++.h>
#define ll long long
using namespace std;
char s[110][110];
int dp[110][110];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    int col = -1;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    memset(dp, 0x7f, sizeof(dp));
    for(int i = 0; i < n && col == -1; i++)
        for(int j = 0; j < m + 2; j++)
            if(s[i][j] == '1')
            {
                col = i;
                break;
            }
    if(col == -1)
    {
        cout << 0 << endl;
        return 0;
    }
    dp[n - 1][0] = 0;
    dp[n - 1][m + 1] = m + 1;
    for(int i = m + 1; i >= 0; i--)
    {
        if(s[n - 1][i] == '1')
        {
            dp[n - 1][0] = i * 2;
            break;
        }
    }
    for(int i = n - 2; i >= col; i--)
    {
        int l = 0, r = m + 1;
        while(l < m + 1 && s[i][++l] == '0');
        while(r > 0 && s[i][--r] == '0');
        dp[i][0] = min(dp[i + 1][m + 1] + m + 2, dp[i + 1][0] + 2 * r + 1);
        dp[i][m + 1] = min(dp[i + 1][0] + m + 2, dp[i + 1][m + 1] + 1 + 2 * (m + 1 - l));
    }
    int l = 0, r = m + 1;
    while(l < m + 1 && s[col][++l] == '0');
    while(r > 0 && s[col][--r] == '0');
    cout << min(dp[col][0] - l, dp[col][m + 1] - (m + 1 - r)) << endl;
    return 0;
}
