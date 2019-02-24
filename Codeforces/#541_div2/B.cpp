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
        cin >> a[i].l >> a[i].r;
    int mmin = min(a[0].l, a[0].r), mmax = max(a[0].l, a[0].r);
    int cnt = mmin + 1;
    int p;
    if(a[0].l < a[0].r)
        p = 0;
    else
        p = 1;
    for(int i = 1; i < n; i++)
    {
        if(p == 0)
        {
            if(a[i].l >= mmax)
            {
                cnt += min(a[i].l, a[i].r) - mmax + 1;;
                if(a[i - 1].l == a[i - 1].r)
                    cnt--;
                if(a[i].l < a[i].r)
                    p = 0;
                else
                    p = 1;
            }
            mmax = max(a[i].l, a[i].r);
            mmin = min(a[i].l, a[i].r);
        }
        else
        {
            if(a[i].r >= mmax)
            {
                cnt += min(a[i].l, a[i].r) - mmax + 1;
                if(a[i - 1].l == a[i - 1].r)
                    cnt--;
                if(a[i].l < a[i].r)
                    p = 0;
                else
                    p = 1;
            }
            mmax = max(a[i].l, a[i].r);
            mmin = min(a[i].l, a[i].r);
        }
    }
    cout << cnt << endl;
    return 0;
}
