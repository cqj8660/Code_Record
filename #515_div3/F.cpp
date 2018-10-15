#include <bits/stdc++.h>
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
int all_length[maxn];
vector<vector<pii> > T;
bool cmp(const pii& a, const pii& b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
int dis(pii a, pii b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
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
        sort(idx.second.begin(), idx.second.end(), cmp);
        ind[idx.first] = s++;
    }
    for(auto idx: t)
    {
        if(idx.second.size() == 1)
            continue;
        if(idx.second[0].second == idx.first)
            all_length[ind[idx.first]] = idx.second[0].first - idx.second.back().first;
        else if(idx.second.back().first == idx.first)
            all_length[ind[idx.first]] = idx.second.back().second - idx.second[0].second;
        else
            all_length[ind[idx.first]] = 2 * idx.first - idx.second.back().first - idx.second[0].second;
    }
    for(auto idx: t)
        T.push_back(idx.second);
    int len = (int)T.size();
//    for(int i = 0; i < len; i++)
//    {
//        if(T[i].size() == 1)
//            continue;
//        if(T[i].back().second == )
//    }
    for(int i = 0; i < len - 1; i++)
    {
        vector<pii> idx = T[i];
        pii a = idx.back(), b = idx[0];
//        cout << a.first << ' ' << a.second << endl;
//        cout << b.first << ' ' << b.second << endl;
        //计算到达下一level的左上角点
        dp[i + 1][0] = min(dis(a, T[i + 1][0]) + dp[i][0], dis(b, T[i + 1][0]) + dp[i][1]) + all_length[i + 1];
        dp[i + 1][1] = min(dis(a, T[i + 1].back()) + dp[i][0], dis(b, T[i + 1].back()) + dp[i][1]) + all_length[i + 1];
    }
    cout << min(dp[len - 1][0], dp[len - 1][1]) << endl;
    return 0;
}
