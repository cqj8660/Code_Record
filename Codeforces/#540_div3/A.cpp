#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
pii a[2000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        cout << min(n * a, (n / 2) * b + (n % 2) * a) << endl;
    }
    return 0;
}
