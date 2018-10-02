#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define eps 1e-6
using namespace std;
const int maxn = 2e5 + 10;
ll m, n;
bool C(ll mid)
{
//    ll t = mid * (mid - 1) / 2;
    ll temp = 2 * (n - m - mid);
    if((temp / mid) < mid - 1 || ((temp / mid) == mid - 1 && temp % mid == 0))
        return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    if(m >= n)
    {
        cout << n << endl;
        return 0;
    }
    ll l = 1, r = n;
    for (int i = 0; i < 100; i++)
    {
        ll mid = (l + r) / 2;
        if(C(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r + m << endl;
    return 0;
}
