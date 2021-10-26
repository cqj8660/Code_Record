#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e3 + 10;
ll dp[maxn][maxn];
ll a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= x; j++)
            dp[i][j] = -1e18;
    dp[0][0] = 0;
    deque<int> q;
    for(int i = 1; i <= x; i++)
    {
        q.push_back(0);
        for(int j = 1; j <= n; j++)
        {
            while(q.size() && q.front() < j - k)
                q.pop_front();
            dp[j][i] = dp[q.front()][i - 1] + a[j];
            while (q.size() && dp[q.back()][i - 1] <= dp[j][i - 1])
                q.pop_back();
            q.push_back(j);
        }
        q.clear();
    }
    ll ans = -1;
    for(int i = n - k + 1; i <= n; i++)
        ans = max(ans, dp[i][x]);
    cout << ans << endl;
    return 0;
}
