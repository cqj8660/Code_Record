#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
const int maxn = 2e5 + 10;
using namespace std;
ll n, T, x = 1e18;
ll a[maxn], ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> T;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        x = min(x, a[i]);
    }
    while(x <= T)
    {
        int cnt = 0;
        ll pre = 0;
        for(int i = 0; i < n; i++)
        {
            if(T >= a[i])
            {
                T -= a[i];
                pre += a[i];
                cnt++;
            }
        }
        ans += T / pre * cnt + cnt;
        T %= pre;
    }
    cout << ans << endl;
    return 0;

}
