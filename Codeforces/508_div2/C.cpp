#include <bits/stdc++.h>
#define ll long long
const int maxn = 2e5 + 10;
ll a[maxn];
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < 2 * n; i++)
        cin >> a[i];
    sort(a, a + 2 * n);
//    for(int i = 0; i < 2 * n; i++)
//        cout << a[i] << ' ';
    ll ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
    ll mmin = INT_MAX;
    for(int i = 1; i <= n - 1; i++)
        mmin = min(a[i + n - 1] - a[i],mmin);
    ans = min(ans, mmin * (a[2 * n - 1] - a[0]));
    cout << ans << endl;
    return 0;
}
