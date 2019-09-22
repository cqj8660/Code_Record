#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 10;
map<int, int> mp;
int preorder[maxn];
struct node
{
    int lson, rson;
};
node tree[maxn];
void insert_tree(int val, int index, int r)
{
    int v = preorder[r];
    if(v > val)
    {
        if(tree[r].lson == -1)
        {
            tree[r].lson = index;
            return;
        }
        else
        {
            insert_tree(val, index, tree[r].lson);
        }
    }
    else
    {
        if(tree[r].rson == -1)
        {
            tree[r].rson = index;
            return;
        }
        else
        {
            insert_tree(val, index, tree[r].rson);
        }
    }
}

int search_lca(int i, int u, int v)
{
    if(preorder[i] >= u && preorder[i] <= v)
        return i;
    if(preorder[i] > u && preorder[i] > v)
        return search_lca(tree[i].lson, u, v);
    return search_lca(tree[i].rson, u, v);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    for(int i = 0; i <= n; i++)
        tree[i].lson = tree[i].rson = -1;
    cin >> preorder[1];
    mp[preorder[1]] = 1;
    for(int i = 2; i <= n; i++)
    {
        cin >> preorder[i];
        mp[preorder[i]] = i;
        insert_tree(preorder[i], i, 1);
    }
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        if(!mp[u] || !mp[v])
        {
            if(mp[u])
                cout << "ERROR: " << v << " is not found.\n";
            else if(mp[v])
                cout << "ERROR: " << u << " is not found.\n";
            else
                cout << "ERROR: " << u << " and " << v << " are not found.\n";
            continue;
        }
        int iu = mp[u], iv = mp[v];
        int lca = search_lca(1, u < v ? u : v, u > v ? u : v);
        if(lca != mp[u] && lca != mp[v])
            cout << "LCA of " << u << " and " << v << " is " << preorder[lca] << ".\n";
        else if(lca == mp[u])
            cout << u << " is an ancestor of " << v << ".\n";
        else
            cout << v << " is an ancestor of " << u << ".\n";
    }
    return 0;
}
