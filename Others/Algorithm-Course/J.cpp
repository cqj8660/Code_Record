#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int maxn = 1e4 + 10;
ll fib[100];
map<ll, ll> mp;
ll dp[maxn][2];
//dp[i][0]表示不把第i个数分解的方案数
//dp[i][1]表示把第i个数进行分解的方案数
void init()
{
    fib[1] = 1;
    fib[2] = 2;
    mp[1] = 1;
    mp[2] = 2;
    for(int i = 3; i < 90; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        mp[fib[i]] = i;
        if(fib[i] > 1LL * 1e18)
            break;
    }
}
int main()
{
    int T; cin >> T;
    ll n;
    init();
    for(int cas = 0;  cas < T; cas++)
    {
        cin >> n;
        vector<ll> v;
        while(n != 0)
        {
            int x = int(lower_bound(fib, fib + 87, n) - fib);
            if(n != fib[x])
                x--;//找到最大的不超过n的fibonacci数
            v.push_back(fib[x]);
            n -= fib[x];
        }
        sort(v.begin(), v.end());
        dp[0][0] = 1;
        dp[0][1] = (mp[v[0]] - 1) / 2;
        int len = (int)v.size();
        for(int i = 1; i < len; i++){
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = (mp[v[i]] - mp[v[i - 1]] - 1) / 2 * dp[i - 1][0] + (mp[v[i]] - mp[v[i - 1]]) / 2 * dp[i - 1][1];
        }
        cout << "case #" << cas << ":\n" << dp[len - 1][0] + dp[len - 1][1] << endl;
    }
    return 0;
}

