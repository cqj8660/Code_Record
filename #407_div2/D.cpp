#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e5 + 10;
using namespace std;
int n, m;
vector<int> g[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(m < n - 1)
    {
        cout << 0 << endl;
        return 0;
    }
    return 0;
}
