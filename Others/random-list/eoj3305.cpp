#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 1;
using namespace std;
const ld eps = 4e-16;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ld a;
    cin >> a;
    srand(time(0));
    ll up, dn, mid;
    while(1)
    {
        dn = rand() % mod;
        mid = dn * a;
        for(up = mid - 10; up <= mid + 10; up++)
        {
            if(fabs((ld)up / dn - a) < eps)
            {
                cout << up << ' ' << dn << endl;
                return 0;
            }
        }
    }

    return 0;
}

