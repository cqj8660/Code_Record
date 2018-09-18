#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6 + 10;
vector<int> g[maxn];
int a[maxn];
int n, dat[2 * maxn  + 100];
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
    if(r <= a || b <= l) return INT_MIN;
    if(a <= l && r <= b) return dat[k];
    else
    {
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    init(t);
    int mmax = 0, mmin = maxn;
    for(int i = 0; i < t; i++)
    {
        cin >> a[i];
        update(i, a[i]);
        g[a[i]].push_back(i);
        mmax = max(a[i], mmax);
        mmin = min(a[i], mmin);
    }
    ll cnt = 0;
    for(int i = mmin; i <= mmax; i++)
    {
        if(g[i].size() >= 2)
        {
            int len = (int)g[i].size();
            ll now = 0;
            for(int j = 0; j < len - 1; j++)
            {
                int q = query(g[i][j], g[i][j + 1], 0, 0, n);
                if(q > i)
                {
                    cnt += (now + 1) * now / 2;
                    now = 0;
                }
                else
                {
                    now++;
                    if(j == len - 2)
                        cnt += (now + 1) * now / 2;
                }
            }
        }
    }
    cout << cnt * 2 << endl;
    
    return 0;
}

