#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iomanip>
#include <cmath>
#define pii pair<int, int>
#define vi vector<int>
#define ll long long
#define eps 1e-3
using namespace std;
const int maxn = 3e5 + 10;
int par[maxn];
int n, k;
struct edge{
    int from, to;
    double cost;
};
struct node{
    int x, y;
}a[maxn];
int ne;
edge es[maxn];
void add(int a, int b, double c)
{
    es[ne++] = edge{a, b, c};
}
bool cmp(const edge& a, const edge& b)
{
    return a.cost < b.cost;
}
void init()
{
    for(int i = 0; i <= n; i++)
        par[i] = i;
}
int f(int i)
{
    if(par[i] == i)
        return i;
    return par[i] = f(par[i]);
}
void unite(int a, int b)
{
    a = f(a);
    b = f(b);
    par[a] = b;
}
bool same(int a, int b)
{
    return f(a) == f(b);
}
double dis(int x, int y)
{
    return sqrt(pow(a[x].x - a[y].x, 2) + pow(a[x].y - a[y].y, 2));
}
bool vis[1000];
int main()
{
    //freopen("/Users/vector/Desktop/in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cas;cin >> cas;
    while(cas--)
    {
        ne = 0;
        cin >> k >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i].x >> a[i].y;
        }
        memset(vis, 0, sizeof(vis));
        init();
        for(int i = 0; i < n - 1; i++)
            for(int j = i + 1; j < n ; j++)
            {
                add(i, j, dis(i, j));
            }
        sort(es, es + ne, cmp);
        vector<edge> q;
        for(int i = 0; i < ne; i++)
        {
            if(same(es[i].from, es[i].to))
                continue;
            q.push_back(es[i]);
            unite(es[i].from, es[i].to);
        }
        cout << fixed << setprecision(2) << q[q.size() - k].cost << endl;
        
    }
    
    return 0;
}

