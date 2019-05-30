#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
const int maxn = 1e3 + 10;
const int INF = 0x7f7f7f7f;
struct edge
{
    int to, cap, rev;
};
vector<edge> G[maxn];
bool used[maxn];
void add_edge(int from, int to, int cap)
{
    G[from].push_back(edge{to, cap, G[to].size()});
    G[to].push_back(edge{from, 0, G[from].size() - 1});
}
int dfs(int v, int t, int f)
{
    if(v == t)
        return f;
    used[v] = true;
    for(int i = 0; i < G[v].size(); i++)
    {
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0)
        {
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t)
{
    int flow = 0;
    while(1)
    {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if(f == 0)
            return flow;
        flow += f;
    }
}
int main()
{
    int cas;
    scanf("%d", &cas);
    for(int idx = 1; idx <= cas; idx++)
    {

        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            G[i].clear();
        while(m--)
        {
            int x, y, c;
            scanf("%d%d%d", &x, &y, &c);
            add_edge(x, y, c);
        }
        printf("Case %d: %d\n", idx, max_flow(1, n));
    }

    return 0;
}
