#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e4 + 10;
int g[150][150], fg[150][150];
vector<pair<string, int> > ans;
int n, m;
void dorow()
{
    for(int i = 1; i <= n; i++)
    {
        int mmin = INT_MAX;
        for(int j = 1; j <= m; j++)
            mmin = min(mmin, g[i][j]);
        while(mmin--)
        {
            ans.push_back(make_pair("row ", i));
            for(int j = 1; j <= m; j++)
                fg[i][j]++;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        if(fg[1][i] < g[1][i])
        {
            int temp = g[1][i] - fg[1][i];
            while(temp--)
            {
                ans.push_back(make_pair("col ", i));
                for(int j = 1; j <= n; j++)
                    fg[j][i]++;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(fg[i][j] != g[i][j])
            {
                cout << -1 << endl;
                exit(0);
            }
    cout << ans.size() << endl;
    for(auto idx: ans)
        cout << idx.first << idx.second << endl;
}
void docol()
{
    for(int i = 1; i <= m; i++)
    {
        int mmin = INT_MAX;
        for(int j = 1; j <= n; j++)
            mmin = min(mmin, g[j][i]);
        while(mmin--)
        {
            ans.push_back(make_pair("col ", i));
            for(int j = 1; j <= n; j++)
                fg[j][i]++;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(fg[i][1] < g[i][1])
        {
            int temp = g[i][1] - fg[i][1];
            while(temp--)
            {
                ans.push_back(make_pair("row ", i));
                for(int j = 1; j <= m; j++)
                    fg[i][j]++;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(fg[i][j] != g[i][j])
            {
                cout << -1 << endl;
                exit(0);
            }
    cout << ans.size() << endl;
    for(auto idx: ans)
        cout << idx.first << idx.second << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];
    if(n < m)
        dorow();
    else
        docol();
    return 0;
}
