#include <bits/stdc++.h>
const int maxn = 2e6 + 10;
typedef long long ll;
int a[110];
int dp[maxn];
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n)
    {
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        memset(dp, -1, sizeof(dp));
        dp[0] = 1;
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = sum; j >= a[i]; j--)
            {
                if(dp[j - a[i]] != -1)
                {
                    dp[j] = 1;
                    if(abs(sum - j - j) < abs(sum - ans - ans))
                        ans = j;
                }
            }
        }
        cout << abs(sum - 2 * ans) << endl;
    }
    return 0;
}

