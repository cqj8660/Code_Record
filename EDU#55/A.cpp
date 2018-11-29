#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, d, y, t;
    cin >> t;
    while(t--)
    {
        cin >> n >> x >> y >> d;
        int ans = INT_MAX;
        if(abs(y - x) % d == 0)
            ans = abs(y - x) / d;
        if((y - 1) % d == 0)
        {
            int t = (y - 1) / d + (x - 1) / d;
            if((x - 1) % d)
                t++;
            ans = min(ans, t);
        }
        if((n - y) % d == 0)
        {
            int t = (n - y) / d + (n - x) / d;
            if((n - x) % d)
                t++;
            ans = min(ans, t);
        }
        if(ans == INT_MAX)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}
