#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e2 + 10;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll a, b, k;
        cin >> a >> b >> k;
        ll ans = (a - b) * (k / 2);
        if(k % 2)
            ans += a;
        cout << ans << endl;
    }
    return 0;
}
