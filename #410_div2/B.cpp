#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define eps 1e-6
using namespace std;
const int maxn = 2e5 + 10;
string a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, len, ans = INT_MAX;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i == 0) len = (int)a[0].length();
        else if(a[i].length() != len)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = 0; i < n; i++)
    {
        int temp = 0;
        for(int j = 0; j < n; j++)
        {
            if(j == i) continue;
            int k;
            for(k = 0; k < len; k++)
            {
                string t = a[j].substr(k) + a[j].substr(0, k);
                if(t == a[i])
                {
                    temp += k;
                    break;
                }
            }
            if(k == len)
            {
                cout << -1 << endl;
                return 0;
            }
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;
    return 0;

}
