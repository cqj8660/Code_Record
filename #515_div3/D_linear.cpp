#include <bits/stdc++.h>
#define ll long long
const int maxn = 2e5 + 10;
using namespace std;
int a[maxn];
int n, m, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int loc = n - 1;
    for(int i = 0; i < m; i++)
    {
        int siz = k;
        while(siz - a[loc] >= 0 && loc >= 0)
            siz -= a[loc--];
    }
    cout << n - 1 - loc << endl;
    return 0;
}
