#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#define ll long long
using namespace std;
const int maxm = 2e3 + 10;
const int maxn = 2e5 + 10;
ll n, data[maxn * 2 - 1], datb[maxn * 2 - 1];
//data保存区间所加值
//datb保存这个区间的和
/*void init(int N)
{
    n = 1;
    while(n < N)
        n *= 2;
    for(int i = 0; i < 2 * n - 1; i++)
        dat[i] = 0;
}*/
void add(int a, int b, int x, int k, int l, int r)
{
    if(a <= l && r <= b)
        data[k] += x;
    else if(l < b && a < r)
    {
        datb[k] += (min(b, r) - max(a, l)) * x;
        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
    }
}
ll sum(int a, int b, int k, int l, int r)
{
    if(b <= l || r <= a)
        return 0;
    else if(a <= l && r <= b)
        return data[k] * (r - l) + datb[k];
    else
    {
        ll res = (min(b, r) -  max(a, l)) * data[k];
        res += sum(a, b, k * 2 + 1, l, (l + r) / 2);
        res += sum(a, b, k * 2 + 2, (l + r) / 2, r);
        return res;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    while(cin >> n >> m)
    {
        //init(N);
        for(int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            add(i, i + 1, t, 0, 0, n);
        }
        /*
        int temp = 1;
        while(temp < n)
            temp *= 2;
        for(int i = n; i < temp; i++)
            update(i, i + 1, 0, 0, )
        */
        while(m--)
        {
            string q;
            int l, r;
            cin >> q >> l >> r;
            if(q[0] == 'Q')
                cout << sum(l - 1, r, 0, 0, n) << endl;
            else
            {
                int v;
                cin >> v;
                add(l - 1, r, v, 0, 0, n);
            }
        }
    }
}
