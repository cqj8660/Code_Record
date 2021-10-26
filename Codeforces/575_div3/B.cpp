#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 10;
ll a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        int cnt = 0, temp = 0;
        vector<int> loc;
        for(int i = 1; i <= n; i++)
        {
            temp += a[i];
            if(temp & 1)
            {
                loc.push_back(i);
                cnt++;
                temp = 0;
            }
        }
        if(cnt < k || (cnt - k) % 2)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for(int i = 0; i < k - 1; i++)
                cout << loc[i] << ' ';
            cout << n << endl;
        }
    }
    return 0;
}
