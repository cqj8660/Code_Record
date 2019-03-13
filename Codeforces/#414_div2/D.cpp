#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 3e5 + 10;
vector<int> g[maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    return 0;
}
