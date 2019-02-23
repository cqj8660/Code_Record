#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 2e5 + 10;
struct node{
    int a, b;
};
int par[maxn];
vector<int> pp[maxn];
int F(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = F(par[node]);
}
void unite(int a, int b)
{
    a = F(a);
    b = F(b);
    if(pp[a].size() > pp[b].size())
    {
        par[b] = a;
        for(auto idx: pp[b])
            pp[a].push_back(idx);
        pp[b].clear();
    }
    else{
        par[a] = b;
        for(auto idx: pp[a])
            pp[b].push_back(idx);
        pp[a].clear();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++)
    {
        par[i] = i;
        pp[i].push_back(i);
    }
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }
    for(auto idx: pp[F(1)])
        cout << idx << ' ';
    cout << endl;
    return 0;
}
