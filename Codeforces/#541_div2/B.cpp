#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 10;
struct pii
{
    int l, r;
};
pii a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].l >> a[i].r;
    }
    ll mmin = min(a[0].l, a[0].r), mmax = max(a[0].l, a[0].r);
    ll cnt = min(a[0].l, a[0].r) + 1;
    int p;
    if(a[0].l < a[0].r)
        p = 0;
    else
        p = 1;
    for(int i = 1; i < n; i++)
    {
        if(p == 0)
        {
            if(a[i].l < mmax)
            {
                mmax = max(a[i].l, a[i].r);
                mmin = min(a[i].l, a[i].r);
                continue;
            }
            else
            {
                cnt += min(a[i].l, a[i].r) - mmax + 1;;
                if(a[i - 1].l == a[i - 1].r)
                    cnt--;
                mmax = max(a[i].l, a[i].r);
                mmin = min(a[i].l, a[i].r);
                if(a[i].l < a[i].r)
                    p = 0;
                else
                    p = 1;
            }
        }
        else
        {
            if(a[i].r < mmax)
            {
                mmax = max(a[i].l, a[i].r);
                mmin = min(a[i].l, a[i].r);
                continue;
            }
            else
            {
                cnt += min(a[i].l, a[i].r) - mmax + 1;
                if(a[i - 1].l == a[i - 1].r)
                    cnt--;
                mmax = max(a[i].l, a[i].r);
                mmin = min(a[i].l, a[i].r);
                if(a[i].l < a[i].r)
                    p = 0;
                else
                    p = 1;
            }
        }
        
    }
    cout << cnt << endl;
    return 0;
}
