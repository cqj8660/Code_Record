#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 2e3 + 10;
vector<int> g[maxn];
int deg[maxn];
string res[maxn];
int par[maxn];
int ans[maxn];
void init(int num)
{
    for(int i = 0; i <= num; i++)
        par[i] = i;
}
int Find(int t)
{
    if(t == par[t])
        return t;
    return par[t] = Find(par[t]);
}
void unite(int a, int b)
{
    a = Find(a);
    b = Find(b);
    par[a] = b;
}
void add_edge(int a, int b)
{
    g[a].push_back(b);
    deg[b]++;
}
int main()
{
    int n, m;
    cin >> n >> m;
    init(n + m);
    for(int i = 0; i < n; i++)
        cin >> res[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(res[i][j] == '=')
                unite(i, j + n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(res[i][j] == '>')
                add_edge(Find(j + n), Find(i));
            else if(res[i][j] == '<')
                add_edge(Find(i), Find(j + n));
    for(int i = 0; i < n + m; i++)
    {
        add_edge(n + m, Find(i));
    }
    queue<int> p;
    memset(ans, -1, sizeof(ans));
    p.push(n + m);
    ans[n + m] = 0;
    while(p.size())
    {
        int t = p.front();
        p.pop();
        for(auto node: g[t])
        {
            ans[node] = ans[t] + 1;
            if(--deg[node] == 0)
                p.push(node);
        }
    }
    for(int i = 0; i < n + m; i++)
    {
        if(ans[Find(i)] == -1 || deg[Find(i)])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++)
        cout << ans[Find(i)] << ' ';
    cout << endl;
    for(int i = 0; i < m; i++)
        cout << ans[Find(i + n)] << ' ';
    cout << endl;
    return 0;

}
