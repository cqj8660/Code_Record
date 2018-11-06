#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define mp make_pair
#define eps 1e-6
#define mo %= MOD
using namespace std;
const int maxn = 2e5 + 10;
ll a[maxn], b[maxn];
ll suma, sumb;
int idx[maxn];
int n;
bool solve(int *p)
{
    ll prea = 0, preb = 0;
    for(int i = 1; i <= n / 2 + 1; i++)
    {
        prea += a[p[i]];
        preb += b[p[i]];
    }
    return 2 * prea >= suma && 2 * preb >= sumb;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        suma += a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        sumb += b[i];
    }
    for(int i = 1; i <= n; i++)
        idx[i] = i;
    while(1)
    {
        random_shuffle(idx + 1, idx + 1 + n);
        if(solve(idx))
        {
            cout << n / 2 + 1 << endl;
            for(int i = 1; i <= n / 2 + 1; i++)
                cout << idx[i] << ' ';
            cout << endl;
            break;
        }
    }
    return 0;
}
