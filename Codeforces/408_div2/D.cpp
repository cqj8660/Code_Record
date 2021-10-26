#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int maxn = 3e5 + 10;
vector<pii> g[maxn];
bool vis[maxn], vis_edge[maxn];
vector<int> ans;
queue<pii> T;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, d, i;
    cin >> n >> k >> d;
    for(int j = 0; j < k; j++)
    {
        cin >> i;
        T.push(pii(i, 0));
        vis[i] = 1;
    }
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(make_pair(v, i));
        g[v].push_back(make_pair(u, i));
    }
    while(T.size())
    {
        pii now = T.front();
        T.pop();
        if(now.second == d)
            continue;
        for(auto id: g[now.first])
            if(!vis[id.first])
            {
                vis[id.first] = 1;
                T.push(pii(id.first, now.second + 1));
                vis_edge[id.second] = 1;
            }
    }
    for(int i = 1; i <= n - 1; i++)
        if(!vis_edge[i])
            ans.push_back(i);
    cout << ans.size() << endl;
    for(auto idx: ans)
        cout << idx << ' ';
    cout << endl;
    return 0;
}
