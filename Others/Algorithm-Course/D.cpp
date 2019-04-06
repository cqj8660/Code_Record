#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e3;
ll dp[100][100];
pair<int, int> a[maxn];
void init(int n)
{
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
        {
            if(i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = 1LL << 62;
        }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cas;
    cin >> cas;
    while (cas--) {
        int n; cin >> n;
        init(n);
        for(int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 0; j <= n - i; j++)
            {
                for(int k = j; k < j + i - 1; k++)
                {
                    dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j][k] + dp[k + 1][j + i - 1] + a[j].first * a[k + 1].first * a[j + i - 1].second);
                }
            }
        }
        cout << dp[0][n - 1] << endl;
    }
    
}
