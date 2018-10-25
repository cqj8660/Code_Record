#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
int a[maxn], b[maxn];
int bit[maxn], n;
bool vis[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a[t] = i;
        b[i] = t;
    }
    int top = 0;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if(vis[t])
            {
                cout << 0 << ' ';
               // top++;
            }
        else
        {
            cout << a[t] - top + 1 << ' ' ;
            for(int j = top; j <= a[t]; j++)
                vis[b[j]] = 1;
            top = a[t] + 1;
        }
    }
    cout << endl;
    return 0;
}
