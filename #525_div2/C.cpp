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
    for(int i = 1; i <= n; i++)
        a[i] += n;
    cout << "1 " << n << ' ' << n << endl;
    ll q = a[n] - 1, mod = a[n] + 1;
    for(int i = n - 1; i >= 1; i--)
    {
//        cout << q << endl;
        ll temp = a[i] / mod * mod + q;
        if(a[i] % mod) temp += mod;
        q--;
        cout << "1 " << i << ' ' << temp - a[i] << endl;
        for(int j = 1; j <= i; j++)
        {
            a[i] += temp - a[i];
//            a[i] %= mod;
        }
    }
    cout << "2 " << n << ' ' << mod << endl;
    for(int i = 1; i <= n; i++)
        cout << i << ' ';
    
    return 0;
}
