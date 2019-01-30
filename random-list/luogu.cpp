#include<iostream>
//#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 10;
ll a[maxn][maxn];
ll dp[maxn][maxn];
int main(){
    int m, n, h;
    cin >> m >> n >> h;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    dp[0][0] = a[0][0] + h;
    if(dp[0][0] < 0)
    {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1; i < m; i++)
    {
        dp[i][0] = dp[i - 1][0] + a[i][0];
        if(dp[i][0] < 0)
            dp[i][0] = -0x7fffffff;
    }
    for(int j = 1; j < n; j++)
    {
        dp[0][j] = dp[0][j - 1] + a[0][j];
        if(dp[0][j] < 0)
            dp[0][j] = -0x7fffffff;
    }
    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
        {
            ll t = max(dp[i - 1][j], dp[i][j - 1]);
            if(t < 0) {dp[i][j] = -0x7fffffff;}
            else
                dp[i][j] =  t + a[i][j];
        }
    cout << max(1LL * -1 ,dp[m - 1][n - 1]) << endl;
    return 0;
}
