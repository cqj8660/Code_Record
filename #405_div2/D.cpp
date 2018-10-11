#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
vector<int> tree[maxn];
ll dp[maxn][10];
int layer[maxn];
int cnt, n, k;
ll ans;
ll sum[maxn];
void dfs(int node, int fa, int lay)
{
    layer[node] = lay;
    for(auto idx: tree[node])
    {
        if(idx == fa) continue;
        dfs(idx, node, lay + 1);
        
        sum[node] += sum[idx];
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, -1, 0);
//    for(int i = 1; i <= n; i++)
//        cout << dp[i] << endl;
    cout << ans / k << endl;
    return 0;
}
