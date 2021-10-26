#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
bool vis[maxn];
string t, p;
bool C()
{
    int i = 0, j = 0;
    int len = (int)t.length();
    int pl = (int)p.length();
    while(j < len && i < pl)
    {
        if(vis[j]){j++;continue;}
        if(t[j] == p[i])
        {
            j++;i++;
        }
        else
            j++;
    }
    if(i == pl)return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t >> p;
    int len = (int)t.length();
    for (int i = 0; i < len; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    int l = 0, r = len + 1;
    for(int i = 0; i < 100; i++)
    {
        int mid = (l + r) / 2;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < mid; i++)
            vis[a[i]] = 1;
        if(C())
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
    return 0;
}
