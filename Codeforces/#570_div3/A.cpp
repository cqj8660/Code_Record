#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool ok(int p)
{
    int res = 0;
    while(p)
    {
        res += p % 10;
        p /= 10;
    }
    return res % 4 == 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(!ok(n))
        n++;
    cout << n << endl;
    return 0;
}
