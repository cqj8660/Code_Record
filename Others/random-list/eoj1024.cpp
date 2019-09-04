#include <bits/stdc++.h>
const int maxn = 2e6 + 10;
typedef long long ll;
using namespace std;
int a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cas;
    cin >> cas;
    while(cas--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int ans = -1e6, temp = 0;
        for(int i = 0; i < n; i++)
        {
            temp += a[i];
            ans = max(ans, temp);
            if(temp < 0)
                temp = 0;
        }
        cout << ans << endl;
    }
    return 0;
}

