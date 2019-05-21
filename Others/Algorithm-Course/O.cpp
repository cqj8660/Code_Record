#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
const int maxm = 1e3 + 10;
bool vis[maxn];
int lowc[maxn], pre[maxn];
int Max[maxn][maxn], cost[maxn][maxn];
bool used[maxn][maxn];
const int inf = 0x7f7f7f7f;
int n, m;
double ans;
int prim()
{
    int res = 0;
    vis[0] = true;
    pre[0] = -1;
    for(int i = 1; i < n; i++)
    {
        lowc[i] = cost[0][i];
        pre[i] = 0;
    }
    for(int i = 1; i < n; i++)
    {
        int minc = inf;
        int v = -1;
        for(int j = 0; j < n; j++){
            if(!vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                v = j;
            }
        }
        if(minc == inf)
            return -1;
        res += minc;
        vis[v] = 1;
        used[v][pre[v]] = used[pre[v]][v] = 1;
        for(int j = 0; j < n; j++){
            if(vis[j] && j != v)
                Max[j][v] = Max[v][j] = max(Max[j][pre[v]], lowc[v]);
            if(!vis[j] && lowc[j] > cost[v][j]){
                lowc[j] = cost[v][j];
                pre[j] = v;
            }
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    memset(cost, inf, sizeof(cost));
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        u--;v--;
        cost[u][v] = cost[v][u] = w;
    }
    int ans = prim();
    int add = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j || cost[i][j] == inf || used[i][j]) continue;
            add = min(add, cost[i][j] - Max[i][j]);
        }
    }
    cout << ans + add<< endl;
    return 0;
}

