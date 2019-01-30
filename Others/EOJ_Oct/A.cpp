#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int gcd(int a, int b)
{
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}
int a[200][200];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    if(n % p && m % p)
        cout << "No" << endl;
    else
    {
        cout << "Yes" << endl;
        int idx = 1;
        int t = m / p;
        for(int i = 0; i < n; i++)
            for(int k = 0; k < t; k++,idx++)
                for(int j = k * p; j < (k + 1) * p; j++)
                    a[i][j] = idx;
        t = m % p;
        for(int i = m / p * p; i < m; i++)
            for(int k = 0; k < n / p; k++, idx++)
                for(int j = k * p; j < (k + 1) * p; j++)
                    a[j][i] = idx;
        for(int i = 0; i < n; i++, cout << endl)
            for(int j = 0; j < m; j++)
                cout << a[i][j] << ' ';
    }
    return 0;
    
}
