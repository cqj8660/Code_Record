#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 3e5 + 10;
vector<int> g[maxn], _g[maxn];
int bas = 1313, col = 1;
int par[maxn], color[maxn];
map<ll, int> q;
vector<int> res[maxn];
ll h[maxn];
ll hsh(int i)//计算哈希值
{
    sort(g[i].begin(), g[i].end());
    ll v = 0;
    for(auto idx: g[i])
        v = v * bas + idx;
    return v;
}
void dfs(int node, int pre)
{
    color[node] = col++;
    for(auto idx: _g[node])
    {
        if(idx == pre)
            continue;
        dfs(idx, node);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        g[i].push_back(i);
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        h[i] = hsh(i);
    int sign = 0;
    for(int i = 1; i <= n; i++)
    {
        if(q[h[i]] == 0)
            q[h[i]] = ++sign;
        res[q[h[i]]].push_back(i);
    }
    for(int i = 1; i <= sign; i++)
    {
        for(auto v: g[res[i][0]])
            if(q[h[v]] != i)
                _g[i].push_back(q[h[v]]);
        sort(_g[i].begin(), _g[i].end());
        _g[i].erase(unique(_g[i].begin(), _g[i].end()), _g[i].end());
    }
    int st = 1;
    for(int i = 1; i <= sign; i++)
        if(_g[i].size() > 2)
        {
            cout << "NO" << endl;
            return 0;
        }
        else if(_g[i].size() == 1)
            st = i;
    dfs(st, 0);
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++)
        cout << color[q[h[i]]] << ' ';
    cout << endl;
    return 0;
}
