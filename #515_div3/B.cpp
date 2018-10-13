#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, r, t;
int solve(int n)
{
    int len = (2 * r - 1);
    int temp = n / len;
    if(n % len) temp++;
    return temp;
}
int a[2000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        
    }
    return 0;
}
