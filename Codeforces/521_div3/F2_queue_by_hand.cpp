#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e3 + 10;
ll a[maxn], que[maxn];
ll dp[maxn][maxn];
int head, tail;
int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= x; j++)
            dp[i][j] = -1e18;
    dp[0][0] = 0;
    for(int i = 1; i <= x; i++)
    {
        que[++tail] = 0;
        for(int j = 1; j <= n; j++)
        {
            while(head <= tail && que[head] < j - k)
                head++;
            dp[j][i] = dp[que[head]][i - 1] + a[j];
            while(head <= tail && dp[que[tail]][i - 1] <= dp[j][i - 1])
                tail--;
            que[++tail] = j;
        }
        head = 1;
        tail = 0;
    }
    ll ans = -1;
    for(int i = n - k + 1; i <= n; i++)
        ans = max(ans, dp[i][x]);
    cout << ans << endl;
    return 0;
}
