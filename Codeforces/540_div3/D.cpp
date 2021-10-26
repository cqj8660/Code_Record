#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 2e5 + 10;
ll a[maxn];
ll n, m, sum = 0;
bool check(int mid)
{
    int id = 1;
    ll s = 0;
    while(id <= n)
    {
        for(int i = 1; i <= mid; i++)
        {
            ll add = a[id] - (id - 1) / mid;
            if(add <= 0)
                return 0;
            s += add;
            if(s >= m)
                return 1;
            id++;
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1, greater<ll>());
    if(sum < m)
    {
        cout << -1 << endl;
        return 0;
    }
    int l = 1, r = (int)n;
    for(int loop = 0; loop < 100; loop++)
    {
        int mid = (l + r) / 2;
        if(check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
    return 0;
}
