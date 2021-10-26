#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
const int maxn = 2e5 + 10;
using namespace std;
vector<ll> p[maxn];
ll sum[maxn];
bool cmp(ll a, ll b)
{
    return a > b;
}
ll ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        p[a].push_back(b);
    }
    for(int i = 1; i <= m; i++)
    {
        sort(p[i].begin(), p[i].end(), cmp);
        ll temp = 0;
        int len = (int)p[i].size();
        for(int j = 0; j < len; j++)
        {
            temp += p[i][j];
            if(temp > 0)
            {
                sum[j] += temp;
                ans = max(ans, sum[j]);
            }
            else
                break;
        }
    }
    cout << ans << endl;
    return 0;

}
