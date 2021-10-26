#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define eps 1e-6
using namespace std;
const int maxn = 3e5 + 10;
vector<int> tree[maxn];
vector<int> ice[maxn];
bool vis[maxn];
int col[maxn];
void dfs1(int node)//用map存储 稍慢
{
    vis[node] = 1;
    int s = 1;
    map<int, int> q;
    for(auto idx: ice[node])
    {
        if(col[idx])
            q.insert(make_pair(col[idx], 1));
    }
    for(auto idx: ice[node])
    {
        while(q[s])
            s++;
        if(!col[idx])
            col[idx] = s++;
    }
    for(auto idx: tree[node])
    {
        if(!vis[idx])
            dfs1(idx);
    }
}
void dfs2(int node)//去掉那个map的log的复杂度
{
    vis[node] = 1;
    int s = 1, ii = 0;
    vector<int> q;
    for(auto idx: ice[node])
        if(col[idx])
            q.push_back(col[idx]);
    q.push_back(INT_MAX);
    sort(q.begin(), q.end());
    for(auto idx: ice[node])
    {
        while(s == q[ii])
        {
            s++;ii++;
        }
        if(!col[idx])
            col[idx] = s++;
    }
    for(auto idx: tree[node])
    {
        if(!vis[idx])
            dfs2(idx);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int t; cin >> t;
        ice[i].resize(t);
        for(auto &idx: ice[i])
            cin >> idx;
    }
    for(int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs2(1);
    for(int i = 1; i <= m; i++)
        if(!col[i])col[i] = 1;
    set<int> t;
    for(int i = 1; i <= m; i++)
        t.insert(col[i]);
    cout << t.size() << endl;
    for(int i = 1; i <= m; i++)
        cout << col[i] << ' ';
    cout << endl;
    return 0;

}
