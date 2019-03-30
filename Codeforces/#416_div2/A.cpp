#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, sum = 0, cnt = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        sum += t;
    }
    while(2 * sum < (2 * k - 1) * n)
    {
        sum += k;
        n++;
        cnt++;
    }
    return 0;
}
