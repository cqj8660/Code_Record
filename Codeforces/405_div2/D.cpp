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
int subtract(int a, int b)
{
    return ((a - b) % k + k) % k;
}
void dfs(int node, int fa, int lay)
{
    sum[node] = dp[node][lay % k] = 1;
    for(auto idx: tree[node])
    {
        if(idx == fa) continue;
        dfs(idx, node, lay + 1);
        for(int i = 0; i < k; i++)
            for(int j = 0; j < k; j++)
            {
                int r = subtract(i + j, 2 * lay);
                // compute distance modulo k
                int t = subtract(k, r);
                // compute x such that (distance + x) is divisible by k
                ans += t * dp[node][i] * dp[idx][j];
            }
        for(int i = 0; i < k; i++)
            dp[node][i] += dp[idx][i];
        sum[node] += sum[idx];
    }
    // in how many pairs we will count the edge from 'a' to its parent?
    ans += sum[node] * (n - sum[node]);
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
    cout << ans / k << endl;
    return 0;
}
