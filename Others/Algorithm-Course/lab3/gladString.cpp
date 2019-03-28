#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 10;
string a, b;
bool cmp(int s1, int e1, int s2, int e2)
{
    for(int i = s1, j = s2; i <= e1; i++, j++)
        if(a[i] - b[j] != 0)
            return false;
    return true;
}
bool rec(int s1, int e1, int s2, int e2)
{
    if((e1 - s1 + 1) % 2)
        return cmp(s1, e1, s2, e2);
    int mid1 = (s1 + e1) >> 1, mid2 = (s2 + e2) >> 1;
    if(rec(s1, mid1, s2, mid2) && rec(mid1 + 1, e1, mid2 + 1, e2))
        return true;
    if(rec(s1, mid1, mid2 + 1, e2) && rec(mid1 + 1, e1, s2, mid2))
        return true;
    return false;
}
void solve()
{
    int len = (int)a.length();
    if(rec(0, len - 1, 0, len - 1))
        puts("Yes");
    else
        puts("No");
}
string smallest(string s)
{
    if(s.length() % 2)
        return s;
    string s1 = smallest(s.substr(0, s.length() / 2));
    string s2 = smallest(s.substr(s.length() / 2));
    if(s1 < s2)
        return s1 + s2;
    return s2 + s1;
}
int main()
{
    cin >> a >> b;
    a = smallest(a);
    b = smallest(b);
    if(a == b)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

