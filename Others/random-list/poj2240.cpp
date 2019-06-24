#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#define pii pair<int, int>
#define ll long long
using namespace std;
map<string, int> mp;
double dis[100][100];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, cas = 1;
    while(cin >> n && n)
    {
        memset(dis, 0, sizeof(dis));
        for(int i = 1; i <= n; i++)
        {
            string s; cin >> s;
            mp[s] = i;
            dis[i][i] = 1;
        }
        cin >> m;
        while(m--)
        {
            string a, b;
            double c;
            cin >> a >> c >> b;
            int pa = mp[a], pb = mp[b];
            dis[pa][pb] = c;
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                for(int k = 1; k <= n; k++)
                {
                    dis[j][k] = max(dis[j][k], dis[j][i] * dis[i][k]);
                }
        cout << "Case " << cas++ << ": ";
        int i;
        for(i = 1; i <= n; i++)
        {
            if(dis[i][i] > 1)
            {
                cout << "Yes" << endl;
                break;
            }
        }
        if(i == n + 1)
            cout << "No" << endl;
    }
    return 0;
}
