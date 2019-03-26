#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 10;
int q[maxn];
int p[maxn];
set<int> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n - 1; i++)
        cin >> q[i];
    int mmin = 0;
    for(int i = 2; i <= n; i++)
    {
        p[i] = p[i - 1] + q[i - 1];
        mmin = min(mmin, p[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        p[i] -= (mmin - 1);
        if(p[i] >= 1 && p[i] <= n)
            ans.insert(p[i]);
    }
    if(ans.size() == n)
    {
        for(int i = 1; i <= n; i++)
            cout << p[i] << ' ';
        cout << endl;
    }
    else
        cout << "-1" << endl;
    return 0;
}
