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
const int maxn = 1e4 + 10;
vector<int> g[maxn];
int deg[maxn], tempd[maxn];
vector<int> seq[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        deg[v]++;
    }
    int k;
    cin >> k;
    vector<int> ans;
    for(int idx = 0; idx < k; idx++)
    {
        for(int i = 0; i <= n; i++)
            tempd[i] = deg[i];
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            if(tempd[t])
            {
                flag = false;
            }
            for(auto idx: g[t])
                tempd[idx]--;
        }
        if(!flag)
            ans.push_back(idx);
            
    }
    for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ' ';
    cout << ans.back() << '\n';
    return 0;
}
