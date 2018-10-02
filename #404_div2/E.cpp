#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
const int maxn = 4e5 + 10;
int n, m, k;
vector<int> g[maxn];
vector<int> path;
bool vis[maxn];
void dfs(int node)
{
    vis[node] = 1;
    path.push_back(node);
    for(auto idx: g[node])
    {
        if(vis[idx]) continue;
        dfs(idx);
        path.push_back(node);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int res = (int)path.size();
    int len = (2 * n) / k;
    if(2 * n % k) len++;
    for(int i = 0, j = 0; i < k; i++)
    {
        if(res <= 0)
        {
            cout << "1 1" << endl;
            continue;
        }
        if(res >= len)
        {
            int t = len;
            cout << t << ' ';
            res -= t;
            while(t--)
                cout << path[j++] << ' ';
            cout << endl;
        }
        else
        {
            cout << res << ' ';
            while(res--)
                cout << path[j++] << ' ';
            cout << endl;
        }
    }
    return 0;
}
