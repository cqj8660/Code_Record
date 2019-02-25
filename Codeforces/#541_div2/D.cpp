#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 2e3 + 10;
vector<int> g[maxn];
int deg[maxn];//入度
int par[maxn];
char s[maxn][maxn];
int res[maxn];
int getf(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = getf(par[node]);
}

void unite(int a, int b)
{
    a = getf(a);
    b = getf(b);
    par[a] = b;
}
void add_edge(int a, int b)
{
    g[a].push_back(b);
    deg[b]++;
}
void init(int n)
{
    for(int i = 0; i <= n; i++)
        par[i] = i;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    init(n + m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(s[i][j] == '=')
                unite(i, n + j);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] == '<')
                add_edge(getf(i), getf(n + j));
            else if(s[i][j] == '>')
                add_edge(getf(n + j), getf(i));
        }
    for(int i = 0; i < n + m; i++)
        add_edge(n + m, getf(i));
    memset(res, -1, sizeof(res));
    res[n + m] = 0;
    queue<int> q;
    q.push(n + m);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(auto v: g[u])
        {
            res[v] = max(res[v], res[u] + 1);
            if(--deg[v] == 0)
                q.push(v);
        }
    }
    for(int i = 0; i < n + m; i++)
    {
        if(res[getf(i)] == -1 || deg[getf(i)] != 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++)
        cout << res[getf(i)] << ' ';
    cout << endl;
    for(int i = 0; i < m; i++)
        cout << res[getf(n + i)] << ' ';
    cout << endl;
    return 0;
}
