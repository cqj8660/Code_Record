#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 2e5 + 10;
int g[maxn], ip[5];
bool vis[maxn];
struct node{
    int idx;
    int price;
};
vector<node> color[5];
struct clo{
    int p, a, b;
    bool operator < (clo pa) const
    {
        return p < pa.p;
    }
}a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].p;
    for(int i = 0; i < n; i++)
        cin >> a[i].a;
    for(int i = 0; i < n; i++)
        cin >> a[i].b;
    int m; cin >> m;
    for(int i = 0; i < m; i++)
        cin >> g[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            if(a[i].a == j || a[i].b == j)
                color[j].push_back(node{i, a[i].p});
        }
    }
    for(int i = 0; i < m; i++)
    {
        int f = g[i];
        while(ip[f] < color[f].size() && vis[color[f][ip[f]].idx])
            ip[f]++;
        if(ip[f] == color[f].size())
        {
            cout << -1 << endl;
            continue;
        }
        cout << color[f][ip[f]].price << ' ';
        vis[color[f][ip[f]++].idx] = 1;
    }
    cout << endl;
    return 0;
}
