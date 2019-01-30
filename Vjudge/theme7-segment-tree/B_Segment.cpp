#include<bits/stdc++.h>
using namespace std;
const int maxm = 5e3 + 10;
const int maxn = 2e5 + 10;
int a[maxn];
int n, dat[2 * maxn - 1];
void init(int n_)
{
    n = 1;
    while(n < n_)
        n *= 2;
    for(int i = 0; i < 2 * n - 1; i++)
        dat[i] = INT_MIN;
}
void update(int k, int a)
{
    k += n - 1;
    dat[k] = a;
    while(k > 0)
    {
        k = (k - 1) / 2;
        dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}
int query(int a, int b, int k, int l, int r)
{
    if(r <= a || b <= l)
        return INT_MIN;
    if(a <= l && r <= b)
        return dat[k];
    else
    {
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int rl = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(vl, rl);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n_, m, a, b;
    string c;
    while(cin >> n_ >> m)
    {
        init(n_);
        for(int i = 0; i < n_; i++)
        {
            int t;
            cin >> t;
            update(i, t);
        }
        while(m--)
        {
            cin >> c >> a >> b;
            if(c[0] == 'Q')
            {
                cout << query(a - 1, b, 0, 0, n) << endl;
            }
            else
            {
                update(a - 1, b);
            }
        }
    }

    return 0;
}
