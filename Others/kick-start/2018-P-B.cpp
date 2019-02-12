#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4;

string rev(string s)
{
    reverse(s.begin(), s.end());
    return s;
}
string swi(string s)
{
    int len = (int)s.length();
    for(int i = 0; i < len; i++)
        if(s[i] == '0')
            s[i] = '1';
    else
        s[i] = '0';
    return s;
}
string a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    a[0] = "";
    a[1] = "0";
    for(int i = 2; i < 10; i++)
    {
        a[i] = a[i - 1] + "0" + swi(rev(a[i - 1]));
        cout << a[i] << endl;
    }
    
    int T;
    cin >> T;
    
    
    return 0;
}
