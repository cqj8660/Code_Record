#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <cctype>
#include <unordered_map>
#define ll long long
using namespace std;
const int maxn = 1e3 + 10;
map<int, int> g[maxn];
int a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nv, ne;
    cin >> nv >> ne;
    while(ne--)
    {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    int m;
    cin >> m;
    while(m--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        bool flag = true;
        for(int i = 0; i < n && flag; i++)
            for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            int u = a[i], v = a[j];
            if(!g[u][v])
            {
                flag = false;
                break;
            }
        }
        if(!flag)
        {
            cout << "Not a Clique\n";
            continue;
        }
        flag = true;
        set<int> other;
        for(int i = 1; i <= nv; i++)
            other.insert(i);
        for(int i = 0; i < n; i++)
            other.erase(a[i]);
        for(auto e: other)
        {
            bool isMax = true;
            for(int i = 0; i < n; i++)
                if(!g[a[i]][e])
                    isMax = false;
            if(isMax)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "Yes\n";
        else
            cout << "Not Maximal\n";
    }
    return 0;
}
