#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
pii a[2000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int len = 0;
        for(int i = 0; len < n; i = (i + 1) % k, len++)
        {
            putchar('a' + i);
        }
        putchar('\n');
    }
    return 0;
}
