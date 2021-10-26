#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        int n, k;
        cin >> n >> k;
        int mx = INT_MIN, mn = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            int t;cin >> t;
            mx = max(mx, t);
            mn = min(mn, t);
        }
        if(mn + k >= mx)
            cout << mn + k << endl;
        else if(mn + k >= mx - k)
            cout << mn + k << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
