#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
const int maxn = 2e5 + 10;
using namespace std;
//每个边缘的最后一个点要不在左上要不在右下
ll dp[maxn][2];
//dp[i][0]表示第i个等级左上方结束
//dp[i][1]表示第i个等级右下方结束
map<int, vector<pii> > t;
map<int, int> ind;
int lev[maxn];//记录每一level的一圈的长度
vector<vector<pii> > T;
bool cmp(const pii& a, const pii& b)
{
    if(a.fi == b.fi)
        return a.se < b.se;
    return a.fi > b.fi;
}
int dis(pii a, pii b)
{
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        t[max(x, y)].push_back(make_pair(x, y));
    }
    t[0].push_back(make_pair(0, 0));
    int s = 0;
    for(auto& idx: t)
    {
        sort(idx.se.begin(), idx.se.end(), cmp);
        ind[idx.fi] = s++;
    }
    for(auto idx: t)
    {
        if(idx.se.size() == 1)
            continue;
        if(idx.se[0].se == idx.fi)
            lev[ind[idx.fi]] = idx.se[0].fi - idx.se.back().fi;
        else if(idx.se.back().fi == idx.fi)
            lev[ind[idx.fi]] = idx.se.back().se - idx.se[0].se;
        else
            lev[ind[idx.fi]] = 2 * idx.fi - idx.se.back().fi - idx.se[0].se;
    }
    for(auto idx: t)
        T.push_back(idx.se);
    int len = (int)T.size();
    for(int i = 0; i < len - 1; i++)
    {
        vector<pii> idx = T[i];
        pii a = idx.back(), b = idx[0];
        dp[i + 1][0] = min(dis(a, T[i + 1][0]) + dp[i][0], dis(b, T[i + 1][0]) + dp[i][1]) + lev[i + 1];
        dp[i + 1][1] = min(dis(a, T[i + 1].back()) + dp[i][0], dis(b, T[i + 1].back()) + dp[i][1]) + lev[i + 1];
    }
    cout << min(dp[len - 1][0], dp[len - 1][1]) << endl;
    return 0;
}
