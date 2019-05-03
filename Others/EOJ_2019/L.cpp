#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    // freopen("C:\\Users\\stu\\Desktop\\in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cas;
    cin >> cas;
    while(cas--)
    {
        int a[10] = {};
        memset(a, 0, sizeof(a));
        int ans = 0;
        for(int i = 1; i <= 6; i++)
            cin >> a[i];
        ans += a[6];
        a[6] = 0;
        ans += a[5];
        a[1] = max(0, a[1] - a[5]);
        a[5] = 0;
        ans += a[4];
        if(a[4] > a[2])
        {
            a[4] -= a[2];
            a[2] = 0;
            a[1] = max(0, a[1] - a[4] * 2);
        }
        else
            a[2] -= a[4];
        ans += a[3] / 2;
        if(a[3] % 2)
        {
            ans++;
            if(a[2])
            {
                a[1] = max(0, a[1] - 1);
                a[2] = max(0, a[2] - 1);
            }
            else
            {
                a[1] = max(0, a[1] - 3);
            }

        }
        ans += a[2] / 3;
        if(a[2] % 3)
        {
            ans++;
            a[1] = max(0, a[1] - 2 * (3 - a[2] % 3));
        }
        ans += a[1] / 6;
        if(a[1] % 6)
            ans++;
        cout << ans << endl;
    }
    return 0;
}


