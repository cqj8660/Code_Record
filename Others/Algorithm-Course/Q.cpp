#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
vector<pair<int, double> > g[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        double w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    return 0;
}

