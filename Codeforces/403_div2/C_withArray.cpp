#include <bits/stdc++.h>
#define vi vector<int>
#define eps 1e-6
using namespace std;
const int maxn = 2e2 + 10;
struct edge{
    int to, nxt;
};
edge q[2 * maxn];
int color[maxn];
int tot = 1;
bool vis[maxn];
int head[maxn];
int n;
void dfs(int node, int fat, int c1, int c2)
{
    int idx = 1;
    for(int i = head[node]; i; i = q[i].nxt)
    {
        edge e = q[i];
        if(e.to == fat) continue;
        for(;idx <= n; idx++)
            if(idx != c1 && idx != c2)
            {
                color[e.to] = idx++;
                break;
            }
        dfs(e.to, node, color[node], color[e.to]);
        
    }
}
void add(int a, int b)
{
    q[tot] = edge{b, head[a]};
    head[a] = tot++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    color[1] = 1;
    dfs(1, -1, 1, -1);
    set<int> count;
    for(int i = 1; i <= n; i++)
        count.insert(color[i]);
    cout << count.size() << endl;
    for(int i = 1; i <= n; i++)
        cout << color[i] << ' ';
    cout << endl;
    return 0;
}
