#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define mp make_pair
#define eps 1e-6
#define mo %= MOD
using namespace std;
const int maxn = 2e3 + 10;
const int MOD = 1e9 + 7;
const int inf = 0x3f3f3ff;
int g[maxn][maxn];
int dis[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cas;
    cin >> cas;
    while(cas--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                cin >> g[i][j];
                if(g[i][j] == -1)
                    dis[i][j] = inf;
                else
                    dis[i][j] = g[i][j];
            }
        bool flag = true;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
            {
                if(dis[i][j] == inf && dis[j][i] == inf)
                    continue;
                else
                {
                    if(dis[i][j] == inf || dis[j][i] == inf)
                        dis[i][j] = dis[j][i] = min(dis[i][j], dis[j][i]);
                    else if(dis[i][j] != dis[j][i])
                        flag = false;
                }
            }
        for(int i = 0; i < n; i++)
        {
            if(dis[i][i] != 0)
            {
                if(dis[i][i] == inf)
                    dis[i][i] = 0;
                else
                    flag = false;
            }
        }
        if(!flag)
        {
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(g[i][j] == -1 || i == j)
                    continue;
                if(g[i][j] != dis[i][j] || dis[i][j] != dis[j][i])
                    flag = false;
            }
        if(!flag)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            cout << "YES" << endl;
            for(int i = 0; i < n; i++, cout << endl)
                for(int j = 0; j < n; j++)
                    cout << dis[i][j] << ' ';
        }
    }
    return 0;
}
