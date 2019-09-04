#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
string s;
const int maxn = 1e3 + 10;
const int maxm = 2e5 + 10;
const int mod = 1e9 + 7;
#define eps 1e-6
ll a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int f, n;
    cin >> f >> n;
    a[0] = a[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int k = 0; k < i; k++)
        {
            a[i] += a[k] * a[i - 1 - k];
            a[i] %= mod;
        }
    }
    cout << a[n] << endl;
    return 0;
}
