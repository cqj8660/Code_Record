#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
struct node{
    ll a, b, c;
    bool operator < (node p) const{
        return c * p.b < p.c * b;
    }
};
node p[maxn];
ll dp[maxn];//dp[j]表示时间为j时的最大美味指数
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, T;
    cin >> T >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i].a;
    for(int i = 0; i < n; i++)
        cin >> p[i].b;
    for(int i = 0; i < n; i++)
        cin >> p[i].c;
    sort(p, p + n);
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = T; j >= p[i].c; j--)
        {
            dp[j] = max(dp[j], dp[j - p[i].c] + p[i].a - j * p[i].b);
            ans = max(dp[j], ans);
        }
    }
    cout << ans << endl;
    return 0;
}
