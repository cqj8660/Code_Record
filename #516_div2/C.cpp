#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e5 + 10;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    for(int i = n - 1; i >= 0; i--)
        cout << s[i];
    cout << endl;
    return 0;

}
