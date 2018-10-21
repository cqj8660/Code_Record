#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int F(string s)
{
    string p = "VK";
    int res = 0, loc = s.find(p);
    while(loc != -1)
    {
        res++;
        loc = s.find(p, loc + 1);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int len = s.length();
    int ans = F(s);
    for(int i = 0; i < len; i++)
    {
        char c = s[i];
        if(c == 'V')
            s[i] = 'K';
        else
            s[i] = 'V';
        ans = max(ans, F(s));
        s[i] = c;
    }
    cout << ans << endl;
    return 0;

}
