#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int q[100];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    q['T' - 'A'] = 4;
    q['C' - 'A'] = 6;
    q['O' - 'A'] = 8;
    q['D' - 'A'] = 12;
    q['I' - 'A'] = 20;
    int ans = 0;
    while(n--)
    {
        string s; cin >> s;
        ans += q[s[0] -'A'];
    }
    cout << ans << endl;
    
}
