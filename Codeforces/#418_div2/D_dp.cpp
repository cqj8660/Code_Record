#include <bits/stdc++.h>
#define ll long long
#define pi acos(-1)
using namespace std;
const int maxn = 2e3 + 10;
struct circle{
    ll x, y, r;
};
circle a[maxn];
vector<int> g[maxn];
int par[maxn];
double dp[maxn][2][2];
bool isInclude(int i, int j)
{
    if(a[i].r >= a[j].r)
        return false;
    ll dis = (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y);
    return dis <= (a[i].r - a[j].r) * (a[i].r - a[j].r);
}
double S(int i)
{
    return pi * a[i].r * a[i].r;
}
void dfs(int id)
{
    double temp[2][2] = {{0}};
    for(auto e: g[id])
    {
        dfs(e);
        for(int i = 0; i <= 1; i++)
            for(int j = 0; j <= 1; j++)
                temp[i][j] += dp[e][i][j];
    }
    dp[id][0][0] = max(temp[0][1] + S(id), temp[1][0] + S(id));
    dp[id][1][0] = max(temp[0][0] - S(id), temp[1][1] + S(id));
    dp[id][0][1] = max(temp[0][0] - S(id), temp[1][1] + S(id));
    dp[id][1][1] = max(temp[0][1] - S(id), temp[1][0] - S(id));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y >> a[i].r;
    double ans = 0;
    for(int i = 0; i < n; i++){//找出i的父结点
        par[i] = -1;
        for(int j = 0; j < n; j++){
            if(isInclude(i, j)){
                if(par[i] == -1 || a[par[i]].r > a[j].r)
                    par[i] = j;
            }
        }
        if(par[i] != -1)
            g[par[i]].push_back(i);
    }
    for(int i = 0; i < n; i++)
    {
        if(par[i] == -1)
        {
            dfs(i);
            ans += dp[i][0][0];
        }
    }
    cout << setprecision(10) << ans << endl;
    return 0;
}
