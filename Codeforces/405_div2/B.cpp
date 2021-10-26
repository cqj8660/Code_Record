#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5;
vector<int> g[maxn];
int par[maxn];
int F(int x)
{
    if(x == par[x])
        return x;
    return par[x] = F(par[x]);
}
void unite(int a, int b)
{
    a = F(a);
    b = F(b);
    par[a] = b;
}
void init(int n)
{
    for(int i = 1; i <= n; i++)
        par[i] = i;
}
ll clu[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    init(n);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }
    for(int i = 1; i <= n; i++)
        clu[F(i)]++;
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += clu[i] * (clu[i] - 1) / 2;
    }
    if(sum == m)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
