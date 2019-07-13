#include <bits/stdc++.h>
const int maxn = 1e7 + 10;
typedef long long ll;
using namespace std;
int dp[maxn];
int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;
    dp[1] = x;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i], dp[i - 1] + x);
        dp[i] = min(dp[i], dp[i + 1] + x);
        if(i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + y);
        dp[i * 2] = min(dp[i * 2], dp[i] + y);
    }
    cout << dp[n] << endl;
    return 0;
}

