#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define eps 1e-6
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int mmax = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mmax = max(mmax, a[i]);
    }
    ll cnt = 0;
    int idx = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i] - a[i - 1] == 1) continue;
        else
        {
            if(a[i] - a[i - 1] > 1)
            {
                cnt += a[i] - a[i - 1] - 1;
                continue;
            }
            else
            {
                cnt += mmax - a[i - 1];
                cnt += a[i];
                continue;
            }
        }
    }
    cout << cnt + n << endl;
}
