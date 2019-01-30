#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
typedef long long ll;
using namespace std;
vector<int> tree[maxn];
vector<int> res;
int l[maxn];
int fat[maxn];
bool vis[maxn];
vector<int> T[maxn];
void build(int node, int layer)
{
    vis[node] = 1;
    l[node] = layer;
    for(auto idx: tree[node])
    {
        if(!vis[idx])
        {
            T[node].push_back(idx);
            fat[idx] = node;
            build(idx, layer + 1);
        }
    }
}
int lca(int a, int b)
{
    while(a != b)
    {
        if(l[a] < l[b])
            b = fat[b];
        else if(l[a] > l[b])
            a = fat[a];
        else
        {
            a = fat[a];
            b = fat[b];
        }
    }
    if(a == 0) return 1;
    else return a;
}
int cf[maxn];
void dfs(int node)
{
    for(auto idx: T[node])
    {
        dfs(idx);
        cf[node] += cf[idx];
    }
}
int times[maxn];
int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        res.push_back(t);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    build(1, 0);//建立一棵以1为根的树
//    for(int i = 1; i <= n; i++)
//        cout << fat[i] << ' ' << l[i] << endl;
    int q; scanf("%d", &q);
    while(q--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int c = lca(a, b);
        cf[a]++;
        cf[b]++;
        cf[c] -= 2;
    }
    dfs(1);
    sort(cf + 1, cf + n + 1, greater<int>());
    sort(res.begin(), res.end());
    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans += 1LL * cf[i + 1] * res[i];
    printf("%lld\n", ans);
    return 0;
}

