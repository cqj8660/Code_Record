#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int a[maxn];
vector<int> g[maxn];
bool maxHeap = true;
bool minHeap = true;
void dfs(int node, bool mode)
{
    if(g[node].size())
    {
        for(auto idx: g[node])
        {
            if(mode)
            {
                if(a[idx] < a[node])
                    minHeap = 0;
            }
            else
            {
                if(a[idx] > a[node])
                    maxHeap = 0;
            }
        }
    }
    for(auto idx: g[node])
        dfs(idx, mode);
}
void dfs2(int node, vector<int> & out)
{
    //cout << a[node] << ' ';
    out.push_back(a[node]);
    for(int i = g[node].size() - 1; i >= 0; i--)
    {
        dfs2(g[node][i], out);
    }
    if(g[node].empty())
    {
        cout << out[0];
        for(int i = 1; i < out.size(); i++)
            cout << ' ' << out[i];
        cout << '\n';
    }
    out.pop_back();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[i / 2].push_back(i);
    }

    dfs(1, 0);
    dfs(1, 1);
    vector<int> t;
    dfs2(1, t);
    if(maxHeap)
        cout << "Max Heap\n";
    else if(minHeap)
        cout << "Min Heap\n";
    else
        cout << "Not Heap\n";
    return 0;
}

