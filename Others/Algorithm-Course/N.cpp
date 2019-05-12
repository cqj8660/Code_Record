#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
const int maxm = 1e3 + 10;
double a[maxn], c[maxn];
double g[maxn][maxm];
int n, m;
double ans;
void pivot(int v, int e)
{
    c[v] /= g[v][e];
    for(int i = 1; i <= n; i++)
        if(i != e)
            g[v][i] /= g[v][e];
    g[v][e] = 1 / g[v][e];
    for(int i = 1; i <= m; i++){
        if(i != v && fabs(g[i][e]) > 0){
            c[i] -= g[i][e] * c[v];
            for(int j = 1; j <= n; j++)
                if(j != e)
                    g[i][j] -= g[i][e] * g[v][j];
            g[i][e] = -g[i][e] * g[v][e];
        }
    }
    ans += a[e] * c[v];
    for(int i = 1; i <= n; i++)
        if(i != e)
            a[i] -= a[e] * g[v][i];
    a[e] = -a[e] * g[v][e];
    
}
double simplex()
{
    while(true){
        int e = 1;
        for(; e <= n; e++)
            if(a[e] > 1e-6) break;//找到一个正的非基本变量作为入基变量
        if(e == n + 1) return ans;
        double mmin = INT_MAX;
        int v = 0;
        for(int i = 1; i <= m; i++){
                if(g[i][e] > 1e-6 && mmin > c[i] / g[i][e])
                {
                    mmin = c[i] / g[i][e];
                    v = i;//找到一个约束最大的作为入基变量
                }
            }
        if(mmin == INT_MAX)
            return mmin;
        pivot(v, e);//v为离基变量, e为入基变量
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];//结果矩阵
    for(int i = 1; i <= m; i++)
    {
        int s, t; cin >> s >> t;
        for(int j = s; j <= t; j++)
            g[i][j] = 1;
        cin >> c[i];//每个志愿者的费用
    }
    int ans = simplex() + 0.5;
    cout << ans << endl;
    return 0;
}

