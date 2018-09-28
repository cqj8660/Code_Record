#include <bits/stdc++.h>
#define vi vector<int>
#define eps 1e-6
using namespace std;
const int maxn = 2e2 + 10;
vector<int> q[maxn];
int color[maxn];
int n;
bool vis[maxn];
map<int, int> hav[maxn];
void dfs(int node, int fat, int c1, int c2)
{
    int index = 1;
    for(int i = 0; i < q[node].size(); i++)
    {
        int idx = q[node][i];
        if(idx == fat) continue;
        for(; index <= n; index++)
            if(index != c1 && index != c2)
            {
                color[idx] = index++;
                break;
            }
        dfs(idx, node, color[idx], color[node]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        q[a].push_back(b);
        q[b].push_back(a);
    }
    color[1] = 1;
    dfs(1, -1, 1, -1);
    int num = 0;
    for(int i = 1; i <= n; i++)
        num = max(num, (int)q[i].size() + 1);
    cout << num << endl;
    for(int i = 1; i <= n; i++)
        cout << color[i] << ' ';
    cout << endl;
    return 0;
}
