#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e5 + 10;
using namespace std;
int a[maxn];
int num[maxn];
int n;
void solve(int v)
{
    int u = sqrt(v) + 1;
    for(int i = 1; i <= u; i++)
    {
        if(i > n) break;
        if(v % i)
        {
            num[i]++;
            if(i != v / i && v / i <= n)
                num[v / i]++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        solve(a[i]);
    for(int i = 1; i <= n; i++)
    {
        
    }
    return 0;
}
