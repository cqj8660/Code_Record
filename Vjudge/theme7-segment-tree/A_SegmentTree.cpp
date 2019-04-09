#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], b[maxn];
int dat[2 * maxn - 1];
int n;
void init(int _n)
{
    n = 1;
    while(n < _n)
        n *= 2;
    for(int i = 0; i < 2 * n - 1; i++)
        dat[i] = 0;
}
void update(int k, int a)
{
    k += n - 1;
    dat[k] = a;
    while(k > 0)
    {
        k = (k - 1) / 2;
        dat[k] = dat[k * 2 + 1] + dat[k * 2 + 2];
    }
}
int query(int a, int b, int k, int l, int r)
{
    if(r <= a || b <= l)
        return 0;
    if(a <= l && b >= r)
        return dat[k];
    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return vl + vr;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas++)
    {
        int q; cin >> q;
        init(q);
        for(int i = 0; i < q; i++)
        {
            int t; cin >> t;
            update(i, t);
        }
        string s;
        cout << "Case " << cas << ":\n";
        while(cin >> s)
        {
            if(s[0] == 'E')
                break;
            if(s[0] == 'Q')
            {
                int l, r; cin >> l >> r;
                cout << query(l - 1, r, 0, 0, n) << endl;
            }
            else if(s[0] == 'A')
            {
                int l, r; cin >> l >> r;
                int val = query(l - 1, l , 0, 0, n);
                update(l - 1, val + r);
            }
            else
            {
                int l, r; cin >> l >> r;
                int val = query(l - 1, l , 0, 0, n);
                update(l - 1, val - r);
            }
        }
    }
    return 0;

}
