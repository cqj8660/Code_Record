#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    int ans = s / n;
    if(s % n)
        ans++;
    cout << ans << endl;
    return 0;
}
