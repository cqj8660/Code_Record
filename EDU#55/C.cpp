#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
const int maxn = 2e5 + 10;
using namespace std;
vector<ll> p[maxn];
vector<ll> sum[maxn];
int len;
bool cmp(ll a, ll b)
{
    return a > b;
}
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
        len = max((int)p[i].size(), len);
        sum[i].resize(p[i].size());
    }
    vector<int> per;
    for(int i = 1; i <= m; i++)
    {
        int le = (int)p[i].size();
        if(le == 0) continue;
        else
            per.push_back(i);
        sum[i][0] = p[i][0];
        for(int j = 1; j < le; j++)
            sum[i][j] = sum[i][j - 1] + p[i][j];
    }
    ll ans = 0;
    for(int i = 0; i < len; i++)
    {
        ll temp = 0;
        for(auto j: per)
        {
            if(p[j].size() > i)
                if(sum[j][i] > 0)
                    temp += sum[j][i];
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;

}
