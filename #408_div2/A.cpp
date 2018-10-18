#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[200];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int loc = m, mmin = 0xffff;
    while(loc++ <= n)
    {
        if(a[loc] && a[loc] <= k)
        {
            mmin = loc - m;
            break;
        }
    }
    loc = m;
    while(loc-- > 0)
    {
        if(a[loc] && a[loc] <= k)
        {
            mmin = min(mmin, m - loc);
            break;
        }
    }
    cout << mmin * 10 << endl;
    return 0;
}
