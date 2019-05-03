#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("C:\\Users\\stu\\Desktop\\in.txt", "r", stdin);
    string s;
    cin >> s;
    if(s.length() == 3)
    {
        cout << (s[1] + 12 - s[0]) * (s[2] - '0');
    }
    else if(s.length() == 5)
    {
        int a = (s[0] - '0')* 10 +s[1] - '0';
        int b = 12 + (s[2] - '0')* 10 + s[3] - '0';
        cout << (b - a) * (s[4] - '0') << endl;
    }
    else
    {
        int a = 0, b = 0;
        if(((s[0] - '0')* 10 +s[1] - '0') >= 2 && ((s[0] - '0')* 10 + s[1] - '0') <= 11)
        {
            a = ((s[0] - '0')* 10 +s[1] - '0');
            b = s[2] - '0' + 12;
            cout << (b - a) * (s[3] - '0') << endl;
        }
        else
        {
            a = s[0] - '0';
            b = ((s[1] - '0')* 10 +s [2] - '0') + 12;
            cout << (b - a) * (s[3] - '0') << endl;
        }
    }
    return 0;
}

