#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e3 + 10;
int res[maxn][30];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
//    freopen("C:\\Users\\cqj86\\Desktop\\in.txt", "r", stdin);
    int n, q;
    string s;
    cin >> n >> s >> q;
    for(int ch = 0; ch < 26; ch++)
    {
        for(int i = 0; i < n; i++)
        {
            int rep = 0;
            for(int j = i; j < n; j++)
            {
                if(s[j] != ch + 'a')
                    rep++;
                res[rep][ch] = max(res[rep][ch], j - i + 1);
            }
        }
        for(int i = 1; i <= n; i++)
            res[i][ch] = max(res[i][ch], res[i - 1][ch]);
    }
    while(q--)
    {
        int m;
        string t;
        cin >> m >> t;
        m = min(m, n);
        char c = t[0];
        cout << res[m][c - 'a'] << endl;
    }
    return 0;
}
