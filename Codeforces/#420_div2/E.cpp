#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e3 + 10;
const ll mod = 1e9 + 7;
ll dp[maxn];
struct segment{
    ll a, b, c;
};
segment p[maxn];
int siz = 15;
struct Matrix{
ll mat[20][20];
};
Matrix res, b;
Matrix mul(Matrix pa, Matrix pb)
{
    Matrix ret;
    memset(ret.mat, 0, sizeof(ret.mat));
    for(int i = 0; i <= siz; i++)
    {
        for(int j = 0; j <= siz; j++)
        {
            for(int k = 0; k <= siz; k++)
            {
                ret.mat[i][j] += (pa.mat[i][k] % mod * pb.mat[k][j] % mod) % mod;
                ret.mat[i][j] %= mod;
            }
        }
    }
    return ret;
}
void quick_pow(Matrix pa, ll k)
{
    while(k)
    {
        if(k & 1)
            res = mul(res, b);
        k >>= 1;
        b = mul(b, b);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    for(int i = 0; i <= siz; i++)
        res.mat[i][i] = 1;
    for(int i = 0; i < n; i++)
        cin >> p[i].a >> p[i].b >> p[i].c;
    for(int i = 0; i < n; i++)
    {
        for(int i = 0; i <= siz; i++)
            for(int j = 0; j <= siz; j++)
                b.mat[i][j] = 0;
        for(int j = 0; j <= p[i].c; j++)
        {
            if(j + 1 <= p[i].c)
                b.mat[j][j + 1]++;
            if(j - 1 >= 0)
                b.mat[j][j - 1]++;
            b.mat[j][j]++;
        }
        if(p[i].b >= k)
            quick_pow(res, k - p[i].a);
        else
            quick_pow(res, p[i].b - p[i].a);
    }
    cout << res.mat[0][0] << endl;
    return 0;
}
