#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e2 + 10;
using namespace std;
int a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] && !a[i + 1] && a[i + 2])
        {
            ans++;
            a[i + 2] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
