#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 2e5 + 10;
ll a[maxn], D[maxn], U[maxn], SU[maxn], SD[maxn];
vector<int> tree[maxn];
int n;
void dfsd (int u, int da)
{
    for (int v : tree[u])
    {
        if (v == da) continue;
        dfsd (v, u);
        SD[u] += SD[v];
        D[u] += D[v] + SD[v];
    }
    SD[u] += a[u];
}

void dfsu (int u, int da)
{
    for (int v : tree[u])
    {
        if (v == da) continue;
        SU[v] += SU[u] + SD[u] - SD[v];
        U[v] += U[u] + D[u] - (D[v] + SD[v]) + SU[v];
        dfsu(v, u);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfsd (1, 0);
    dfsu (1, 0);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, U[i] + D[i]);
    cout << ans << endl;
    return 0;
}
