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
    int n;
    cin >> n;
    for(int i = 1; i <= n / 2; i++)
        if(i % 2)cout << "aa";
        else cout << "bb";
    if(n % 2)
    {
        if((n / 2) % 2)
            cout << "b";
        else
            cout << "a";
    }
    cout << endl;
    return 0;

}
