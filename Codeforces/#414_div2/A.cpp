#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
map<int, int> loc;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if(t > b && t < c)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
