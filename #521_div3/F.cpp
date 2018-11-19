#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e3 + 10;
using namespace std;
int a[maxn];
int dp[maxn][maxn];//dp[i][j]表示在最后一个选中的是i且取了j个的最大beauty值
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
//    if(n / k + (n % k == 0) > x)
//    {
//        cout << -1 << endl;
//        return 0;
//    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; )
    }
    return 0;
}
