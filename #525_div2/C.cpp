#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 1e4 + 10;
ll a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << n + 1 << endl;
    ll mod = n + 1;
    for(int i = n; i >= 1; i--)
    {
        ll temp = (1 + a[i] / mod) * mod + i;
        ll add = temp - a[i];
        cout << "1 " << i << ' ' << add << endl;
        for(int j = 1; j <= i; j++)
        {
            a[j] += add;
            a[j] %= mod;
        }
    }
    cout << "2 " << n << ' ' << n + 1 << endl;
    return 0;
}
