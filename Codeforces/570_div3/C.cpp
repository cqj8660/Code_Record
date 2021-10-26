#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll k, n, a, b;
bool solve(ll mid, ll k)
{
    k -= (mid - 1) * a;
    if(k <= a)
        return false;
    k -= a;
    ll N = (k - b) / b + mid;
    k -= (k - b) / b * b;
    if(k > b)
        N++;
    return N >= n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        cin >> k >> n >> a >> b;
        ll l = 0, r = k / a + 10;
        ll ans = -1;
        for(int p = 0; p < 50; p++)
        {
            ll mid = (l + r) >> 1;
            if(solve(mid, k))
            {
                l = mid;
                ans = l;
            }
            else
                r = mid;
        }
        cout << min(ans, n) << endl;
    }
    return 0;
}
