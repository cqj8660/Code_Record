#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
const int maxn = 1e4 + 10;
struct node{
    int to;
    ll cost;
};
vector<node> tree[maxn];
ll sum[maxn], dp[maxn];
int n;
void dfs(int now, int fa)
{
    sum[now] = 1;
    for(auto idx: tree[now])
    {
        if(idx.to == fa) continue;
        dfs(idx.to, now);
        sum[now] += sum[idx.to];
        dp[now] += dp[idx.to] + sum[idx.to] * (n - sum[idx.to]) * idx.cost;
    }
}
int main()
{
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        for(int i = 0; i < maxn; i++)
            tree[i].clear();
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        scanf("%d", &n);
        int a, b, d;
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d%d", &a, &b, &d);
            tree[a].push_back(node{b, d});
            tree[b].push_back(node{a, d});
        }
        dfs(0, -1);
        double ans = 1.0 * dp[0] / (n * (n - 1) / 2);
        printf("%.8f\n", ans);
    }
    
    return 0;
}
