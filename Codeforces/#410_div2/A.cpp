#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());
    int cnt = 0;
    for(int i = 0; i < s.length(); i++)
        if(s[i] != t[i]) cnt++;
    if(cnt == 2 || (cnt == 0 && s.length() % 2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
    
}
