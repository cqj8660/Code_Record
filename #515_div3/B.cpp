#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, r, t;
const int maxn = 2e3 + 10;
int a[maxn], b[maxn], dp[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i])cnt++;
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i])
            for(int j = max(0, i - r + 1); j < min(n, i + r); j++)
                dp[j]++;
    }
    for(int i = 0; i < n; i++)
        if(dp[i] == 0)
        {
            cout << -1;
            return 0;
        }
    for(int i = 0; i < n; i++)
    {
        int f = 1;
        for(int j = max(0, i - r + 1); j < min(n, i + r); j++)
        {
            dp[j]--;
            if(dp[j] == 0) f = 0;
        }
        if(f) cnt--;
        else
        {
            for(int j = max(0, i - r + 1); j < min(n, i + r); j++)
                dp[j]++;
        }
    }
    cout << cnt << endl;
    return 0;
}
