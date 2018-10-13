#include <bits/stdc++.h>
#define ll long long
const int maxn = 2e5 + 10;
using namespace std;
struct node{
    int mode, v;
}a[maxn];
int vis[maxn];
set<int> Q;
map<int, int> T[2];
int s[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    int l = 0, r = 1;
    for(int i = 0; i < q; i++)
    {
        char c; int v;
        cin >> c >> v;
        if(c == 'L')
            s[v] = l--;
        else if(c == 'R')
            s[v] = r++;
        else
            cout << min(s[v] - l - 1, r - s[v] - 1) << endl;
    }
    return 0;
}
