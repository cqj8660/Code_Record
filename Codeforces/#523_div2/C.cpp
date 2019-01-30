#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e6 + 10;
const int MOD = 1e9 + 7;
using namespace std;
ll a[maxn], dp[maxn], ans, upper;
vector<int> factor[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        upper = max(upper, a[i]);
    }
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= upper; j += i)
            factor[j].push_back(i);
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        int len = (int)factor[a[i]].size();
        ll t = a[i];
        for(int j = len - 1; j >= 0; j--)
        {
            int x = factor[t][j];
            ans = (ans + dp[x - 1]) % MOD;
            dp[x] = (dp[x] + dp[x - 1]) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
