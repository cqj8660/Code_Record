#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 1e4 + 10;
const int inf = 0x7f7f7f7f;
pii a[maxn];
bool vis[maxn];
ll dis[maxn];
int n, m, k;
void spfa(int s)
{
    memset(dis, 0x7f, sizeof(dis));
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    while(q.size())
    {
        int t = q.front();
        q.pop();
        vis[t] = 0;
        for(int i = 1; i <= k; i++)
        {
            if(i == t) continue;
            int dx = abs(a[i].fi - a[t].fi);
            int dy = abs(a[i].se - a[t].se);
            ll val = 0;
            if(dx + dy == 1)
                val = 0;
            else if(dx <= 2 || dy <= 2)
                val = 1;
            else
                val = inf;
            if(dis[i] > dis[t] + val)
            {
                dis[i] = dis[t] + val;
                if(!vis[i]){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }

    }

}
int main()
{
    cin >> n >> m >> k;
    bool flag = true;
    for(int i = 1; i <= k; i++)
    {
        cin >> a[i].fi >> a[i].se;
        if(a[i].fi == n && a[i].se == m)
            flag = false;
    }
    if(flag)
        a[++k] = make_pair(n + 1, m + 1);
    spfa(1);
    if(dis[k] >= inf)
        cout << -1 << endl;
    else
        cout << dis[k] << endl;
    return 0;
}
