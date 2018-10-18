#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5 + 10;
struct e
{
    int to, nxt;
} g[2 * maxn];
int head[maxn];
int a[maxn];
int n, maxi, maxv = INT_MIN, edge = 1;
map<int, int> q;
bool judge()
{
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        if(a[i] == maxv)
            cnt++;
        for(int j = head[i]; j; j = g[j].nxt)
        {
            if(a[g[j].to] == maxv)
                cnt++;
        }
        if(cnt == q[maxv])
            return true;
    }
    return false;
}
void add_edge(int u, int v)
{
    g[edge] = e{v, head[u]};
    head[u] = edge++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        q[a[i]]++;
        if(a[i] > maxv)
        {
            maxv = a[i];
            maxi = i;
        }
    }
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    int exto = 0;
    for(int i = head[maxi]; i; i = g[i].nxt)
        if(a[g[i].to] == maxv - 1) exto++;
    if(exto == q[maxv - 1] && q[maxv] == 1)
        cout << maxv << endl;
    else if(judge())
        cout << maxv + 1 << endl;
    else
        cout << maxv + 2 << endl;
    return 0;
}
