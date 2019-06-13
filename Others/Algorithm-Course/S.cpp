#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int maxn = 1e3 + 10;
vector<pii> tree[maxn];
bool vis[maxn];
int pre[maxn], ans;
void dfs(int i, int pre, int dist)
{
    if(vis[i])
    {
        ans = max(ans, dist);
        return;
    }
    for(auto idx: tree[i])
        if(idx.first != pre)
            dfs(idx.first, i, dist + idx.second);
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int s, t, d;
        cin >> s >> t >> d;
        tree[s].push_back(make_pair(t, d));
        tree[t].push_back(make_pair(s, d));
    }
    queue<pii> q;
    q.push(make_pair(1, 0));
    vis[1] = 1;
    int s = 1, maxdis = 0;
    while(q.size())
    {
        pii v = q.front();
        q.pop();
        if(v.second > maxdis)
        {
            maxdis = v.second;
            s = v.first;
        }
        for(auto idx: tree[v.first])
        {
            if(!vis[idx.first])
            {
                vis[idx.first] = 1;
                q.push(make_pair(idx.first, idx.second + v.second));
            }
        }
    }
    q.push({s, 0});
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    vis[s] = 1;
    int e = 0;
    maxdis = 0;
    while(q.size())
    {
        pii v = q.front();
        q.pop();
        if(v.second > maxdis)
        {
            maxdis = v.second;
            e = v.first;
        }
        for(auto idx: tree[v.first])
        {
            if(!vis[idx.first])
            {
                vis[idx.first] = 1;
                pre[idx.first] = v.first;
                q.push({idx.first, idx.second + v.second});
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    while(pre[e] != -1)
    {
        vis[e] = 1;
        e = pre[e];
    }
    vis[e] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
            dfs(i, 0, 0);
    }
    cout << ans << endl;
    return 0;
}

