#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

vector<int> g[maxn];
int color[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cas;
    cin >> cas;
    while(cas--)
    {
        set<int> st;
        for(int i = 0; i < n; i++)
        {
            cin >> color[i];
            st.insert(color[i]);
        }
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            for(auto idx: g[i])
            {
                if(color[idx] == color[i])
                    flag = false;
            }
        }
        if(flag)
        {
            cout << st.size() << "-coloring\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}

