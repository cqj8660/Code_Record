#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 3e5 + 10;
vector<int> tree[maxn];
int color[maxn];
int blue, red, res;
int cnt[maxn][2];//0为红 1为蓝

void dfs(int node, int pre)
{
    for(auto idx: tree[node])
    {
        if(idx == pre)
            continue;
        dfs(idx, node);
        cnt[node][0] += cnt[idx][0];
        cnt[node][1] += cnt[idx][1];
    }
        if((cnt[node][0] == red && cnt[node][1] == 0) || (cnt[node][1] == blue && cnt[node][0] == 0))
            res++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> color[i];
        if(color[i] == 1)
        {
            red++;
            cnt[i][0]++;
        }
        if(color[i] == 2)
        {
            blue++;
            cnt[i][1]++;
        }
    }
    for(int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, 0);
    cout << res << endl;
    return 0;
}
