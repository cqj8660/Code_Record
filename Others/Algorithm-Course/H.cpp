#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 2e4 + 10;
ll a[maxn];
ll dp[maxn]; //dp[i]表示以i结尾的该行最后一个单词的最小整齐度
ll res[maxn];
ll f(ll q)
{
    return q * q * q;
}
int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        memset(dp, 0, sizeof(dp));
        memset(res, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            res[i] = res[i - 1] + a[i];
        }
        if(res[n] + n - 1 <= m)
        {
            cout << 0 << endl;
            continue;
        }
        for(ll i = 1; i <= n; i++)
        {
            ll val = f(m - a[i]);
            dp[i] = dp[i - 1] + val;
            for(ll j = i - 1; j >= 1; j--)
            {
                if(res[i] - res[j - 1] + i - j > m)
                    break;
                dp[i] = min(dp[i], dp[j - 1] + f(m - (res[i] - res[j - 1] + i - j)));
            }
        }
        //        for(int i = 1; i <= n; i++)
        //            cout << dp[i] << endl;
        ll ans = 1LL << 61;
        for(int i = n; i >= 1; i--)
        {
            ll temp = res[n] - res[i - 1];
            ans = min(ans, dp[i]);
            if(temp + n - i > m)
                break;
        }
        cout << ans << endl;
        
    }
    
}
