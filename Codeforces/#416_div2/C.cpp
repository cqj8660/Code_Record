#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e4 + 10;
int a[maxn];
int beg[maxn], ter[maxn];
int dp[maxn];
bool vis[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(beg[a[i]] == 0)
            beg[a[i]] = i;
        ter[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1];
        memset(vis, 0, sizeof(vis));
        int res = 0, st = i;
        for(int j = i; j >= 1; j--)
        {
            if(!vis[a[j]]){
                if(ter[a[j]] > i)
                    break;
                st = min(st, beg[a[j]]);
                res = res xor a[j];
                vis[a[j]] = 1;
            }
            if(j == st)
                dp[i] = max(dp[i], dp[j - 1] + res);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
