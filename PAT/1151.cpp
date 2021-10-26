#include<bits/stdc++.h>

const int maxn = 1e4 + 10;
int pre[maxn], mid[maxn];
using namespace std;
unordered_map<int, int> mp;
unordered_map<int, int> midp;
int find_lca(int locu, int locv, int pl, int pr, int ml, int mr)
{
    int nowNode = pre[pl], midloc = ml;
    midloc = midp[nowNode];
    int cntl = 0, cntr = 0;
    if((midloc >= locu && midloc <= locv) || (midloc <= locu && midloc >= locv))
        return pl;
    if(midloc > locu && midloc > locv)
    {
        int len = midloc - ml;
        return find_lca(locu, locv, pl + 1, pl + len, ml, ml + len - 1);
    }
    else
    {
        int len = midloc - ml;
        return find_lca(locu, locv, pl + 1 + len, pr, midloc + 1, mr);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> mid[i];
        midp[mid[i]] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> pre[i];
        mp[pre[i]] = i;
    }
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        if(!mp[u] || !mp[v])
        {
            if(mp[u])
                cout << "ERROR: " << v << " is not found.\n";
            else if(mp[v])
                cout << "ERROR: " << u << " is not found.\n";
            else
                cout << "ERROR: " << u << " and " << v << " are not found.\n";
            continue;
        }
        int lca = find_lca(midp[u], midp[v], 1, n, 1, n);
        if(lca != mp[u] && lca != mp[v])
            cout << "LCA of " << u << " and " << v << " is " << pre[lca] << ".\n";
        else if(lca == mp[u])
            cout << u << " is an ancestor of " << v << ".\n";
        else
            cout << v << " is an ancestor of " << u << ".\n";
    }
    return 0;
}
