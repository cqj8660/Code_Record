#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a , a + n);
    ll ans = 0;
    for(int i = 0; i < n - 1; i += 2)
        ans += a[i + 1] - a[i];
    cout << ans << endl;
    return 0;
}
