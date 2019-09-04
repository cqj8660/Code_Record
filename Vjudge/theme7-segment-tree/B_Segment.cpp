#include<bits/stdc++.h>
using namespace std;
const int maxm = 5e3 + 10;
const int maxn = 2e5 + 10;
int a[maxn];
int n, dat[2 * maxn - 1];
void init(int N)
{
    n = 1;
    while(n < N)
        n <<= 1;
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
int query(int a, int b, int l, int r, int k)
{
    if(a >= r || b <= l)
        return INT_MIN;
    if(a <= l && b >= r)
        return dat[k];
    return max(query(a, b, l, (l + r) / 2, k * 2 + 1), query(a, b, (l + r) / 2, r, k * 2 + 2));
}
void update(int i, int k)
{
    i += n - 1;
    dat[i] = k;
    while(i > 0)
    {
        k = (k - 1) / 2;
        dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
}
int query(int a, int b, int l, int r, int k)
{
    if(a <= l && r <= b)
        return dat[k];
    else if(r <= a || b <= l)
        return INT_MAX;
    else{
        int vl = query(a, b, l, (l + r) / 2, k * 2 + 1);
        int rl = quert(a, b, (l + r) / 2, r, k * 2 + 2);
        return min(vl, rl);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, m;
    string c;
    while(cin >> N >> m)
    {
        init(N);
        for(int i = 0; i < N; i++)
        {
            int t; cin >> t;
            update(i, t);
        }
        while(m--)
        {
            string q; int l, r;
            cin >> q >> l >> r;
            if(q[0] == 'Q')
                cout << query(l - 1, r, 0, n, 0) << endl;
            else
                update(l - 1, r);
        }

    }
    return 0;
}
