#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6 + 10;
struct edge
{
    int from, to;
    ll cost;
    bool operator < (const edge& p)
    {
        return cost < p.cost;
    }
};
vector<edge> es;
ll dis[maxn];
ll solves(char *s)
{
    int len = strlen(s);
    ll res = 0;
    int loc = - 1;
    for(int i = 0; i < len; i++)
    {
        if(s[i] == '.')
            loc = i;
        if(isdigit(s[i]))
            res = res * 10 + s[i] - '0';
    }
    int time = 5 - len + loc;
    if(loc == -1)
        time = 4;
    while(time--)
        res *= 10;
    if(s[0] == '-')
        res *= -1;
    return res;
}
int main()
{
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        char s[100];
        scanf("%d%d%s", &u, &v, s);
        es.push_back(edge{u, v, solves(s)});
    }
    sort(es.begin(), es.end());
    fill(dis, dis + n + 5, 1e17);
    dis[s] = 0;
    int times = 3;
    while(times--)
    {
        for(int i = 0; i < m; i++)
        {
            if(dis[es[i].to] > dis[es[i].from] + es[i].cost)
            {
                dis[es[i].to] = dis[es[i].from] + es[i].cost;
            }
        }
        for(int i = m - 1; i >= 0; i--)
        {
            if(dis[es[i].to] > dis[es[i].from] + es[i].cost)
            {
                dis[es[i].to] = dis[es[i].from] + es[i].cost;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%.4f\n", val * 1.0 / 10000);
    return 0;
}

