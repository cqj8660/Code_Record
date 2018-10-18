#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e6 + 10;
using namespace std;
ll n, m, self_loop;
vector<int> g[maxn];
bool vis[maxn];
int deg[maxn];
void dfs(int nod)
{
    vis[nod] = 1;
    for(auto idx: g[nod])
    {
        if(vis[idx])
            continue;
        dfs(idx);
    }
}
ll ans = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++;deg[v]++;
        if(u == v) {
            self_loop++;
            continue;
        }
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if(g[i].size())
        {
            dfs(i);
            break;
        }
    for(int i = 1; i <= n; i++)
        if(vis[i] == 0 && deg[i])//如果图不联通
        {
            cout << 0 << endl;
            return 0;
        }
    ans += self_loop * (self_loop - 1) / 2;//两个自环
    ans += self_loop * (m - self_loop);//一个自环一条边
    for(int i = 1; i <= n; i++)//同一个顶点出发的两条边
    {
        ll len = (ll)g[i].size();
        ans += len * (len - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
