#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e3 + 10;
double p[maxn], q[maxn];
double dp[maxn][maxn], w[maxn][maxn];
int main()
{
    int n;
    cin >> n;
    p[0] = 0;
    for(int i = 1; i < n + 1; i++)
        cin >> p[i];
    for(int i = 0; i < n + 1; i++)
        cin >> q[i];
    for(int i = 1; i <= n + 1; i++)
        dp[i][i - 1] = w[i][i - 1] = q[i - 1];
    for(int l = 1; l <= n; l++)
    {
        for(int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for(int r = i; r <= j; r++)
            {
                double t = dp[i][r - 1] + dp[r + 1][j] + w[i][j];
                if(t < dp[i][j])
                    dp[i][j] = t;
            }
        }
    }
    cout << fixed << setprecision(6) <<  dp[1][n] << endl;
    return 0;
}
