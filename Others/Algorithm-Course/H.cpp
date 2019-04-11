#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 2e4 + 10;
ll a[maxn], pre[maxn];
ll dp[maxn]; //dp[i]表示以i结尾的该行最后一个单词的最小整齐度
inline ll f(ll q)
{
    return q * q * q;
}
int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        //M为每行容纳的字符数
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + f(m - a[i]);
            for(int j = i - 1; j >= 1; j--)
            {
                if(pre[i] - pre[j - 1] + i - j > m)
                    break;
                dp[i] = min(dp[i], dp[j - 1] + f(m - pre[i] + pre[j - 1] - i + j));
            }
        }
        //        for(int i = 1; i <= n; i++)
        //            cout << dp[i] << endl;
        ll ans = 1LL << 60;
        for(int i = n; i >= 0; i--)//0表示一行就可以容纳所有单词
        {
            ans = min(ans, dp[i]);
            if(pre[n] - pre[i - 1] + n - i > m)
                break;
        }
        cout << ans << endl;
    }
    
}

