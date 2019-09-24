#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#define ll long long
using namespace std;
const int maxn = 1e3 + 10;
const int maxm = 2e4 + 10;
struct edge{
    int to, cost;
};
vector<edge> g[maxn];
int dist[maxn];
bool visit[maxn];
int graph[maxn][maxn];
int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n, m;
    cin >> n >> m;
    memset(graph, 0x7f, sizeof(graph));
    while(m--)
    {
        int u, v, val;
        cin >> u >> v >> val;
        graph[u][v] = graph[v][u] = val;
        g[u].push_back(edge{v, val});
        g[v].push_back(edge{u, val});
    }
    int k;
    cin >> k;
    while(k--)
    {
        memset(visit, 0, sizeof(visit));
        int source;
        cin >> source;
        dist[source] = 0;
        visit[source] = 1;
        for(int i = 1; i <= n; i++)
            dist[i] = graph[i][source];
        bool ifdijk = true;
        for(int i = 2; i <= n; i++)
        {
            int t;
            cin >> t;
            bool flag = true;
            for(int j = 1; j <= n; j++)
            {
                if(!visit[j] && dist[j] < dist[t])
                    flag = false;
            }
            if(!flag)
                ifdijk = false;
            visit[t] = 1;
            for(int j = 1; j <= n; j++)
            {
                if(visit[j]) continue;
                dist[j] = min(dist[j], dist[t] + graph[t][j]);
            }

        }
        if(ifdijk)
            cout << "Yes\n";
        else
            cout << "No\n";
    }


    return 0;
}
