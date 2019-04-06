#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1000 + 10;
int a[maxn], b[maxn];
int dp[40][40][40][40];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        b[t]++;
    }
    memset(dp, -0x7f, sizeof(dp));
    dp[0][0][0][0] = a[1];
        for(int c1 = 0; c1 <= b[1]; c1++)
            for(int c2 = 0; c2 <= b[2]; c2++)
                for(int c3 = 0; c3 <= b[3]; c3++)
                    for(int c4 = 0; c4 <= b[4]; c4++)
                    {
                        int temp = c1 + c2 * 2 + c3 * 3 + c4 * 4 + 1;
                        if(c4 >= 1)
                            dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4], dp[c1][c2][c3][c4 - 1] + a[temp]);
                        if(c3 >= 1)
                            dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4], dp[c1][c2][c3 - 1][c4] + a[temp]);
                        if(c2 >= 1)
                            dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4], dp[c1][c2 - 1][c3][c4] + a[temp]);
                        if(c1 >= 1)
                            dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4], dp[c1 - 1][c2][c3][c4] + a[temp]);
                    }
    cout << dp[b[1]][b[2]][b[3]][b[4]] << endl;
    return 0;
}

