#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
const int maxn = 4e2 + 10;
vector<int> g[maxn];
int w[maxn][maxn];
int pre[maxn], vis[maxn];
int n, m;
void addEdge(int u, int v, int c)
{
    g[u].push_back(v);
    g[v].push_back(u);
    w[u][v] = c;
}
bool augment_path(int s, int t)//是否存在s到t的增广路
{
    queue<int> q;
    q.push(s);
    memset(pre, -1, sizeof(pre));
    memset(vis, 0, sizeof(vis));
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto v: g[u]){
            if(!vis[v] && w[u][v] > 0)
            {
                vis[v] = 1;
                pre[v] = u;
                if(v == t)
                    continue;
                q.push(v);
            }
        }
    }
    return pre[t] != -1;
}
int update(int s, int t)
{
    int flow = INT_MAX;
    int u = t;
    while(u != s)
    {
        flow = min(flow, w[pre[u]][u]);
        u = pre[u];
    }
    u = t;
    while(u != s)
    {
        w[pre[u]][u] -= flow;
        w[u][pre[u]] += flow;
        u = pre[u];
    }
    return flow;
}
int max_flow(int s, int t)
{
    int res = 0;
    while(augment_path(s, t))
    {
        for(auto u: g[t])
        {
            if(!vis[u] || w[u][t] <= 0) continue;
            pre[t] = u;
            res += update(s, t);
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int col = 0, row = 0;
    bool f = 1;
    int vs = 0, vr = n + m + 1;
    for(int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        addEdge(vs, i, x);
        if(x > m)
            f = 0;
        col += x;
    }
    for(int i = 1; i <= m; i++)
    {
        int x; cin >> x;
        addEdge(i + n, vr, x);
        if(x > n)
            f = 0;
        row += x;
    }
    if(row != col)
        f = 0;
    if(!f)
    {
        cout << "impossible" << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            addEdge(i, j + n, 1);
    int flow = max_flow(vs, vr);
    if(flow != col)
    {
        cout << "impossible" << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++, cout << endl)
    {
        for(int j = 1; j <= m; j++){
            int t = w[j + n][i];
            w[i][j + n] = w[j + n][i] = 0;
            if(t) {
                w[vs][i] = w[j + n][vr] = 1;
                if (augment_path(vs, vr)) {
                    update(vs, vr);
                    t = 0;
                }else {
                    w[vs][i] = w[j + n][vr] = 0;
                }
            }
            cout << t;
        }
    }
    return 0;
}
