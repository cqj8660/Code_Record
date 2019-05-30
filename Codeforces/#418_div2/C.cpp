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
    while(q--)
    {
        int m, fixedm;
        string t;
        cin >> m >> t;
        fixedm = m;
        char c = t[0];
        if(res[m][c - 'a'])
        {
            cout << res[m][c - 'a'] << endl;
            continue;
        }
        int l = 0, ans = 0, len = 0;
        for(int r = 0; r < n; r++){
            if(s[r] != c)
                len++;
            while(len > m){
                if(s[l] != c)
                    len--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        res[fixedm][c - 'a'] = ans;
        cout << ans << endl;
    }
    return 0;
}
