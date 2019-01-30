#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e4;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    for(int i = 1; i <= 100; i++)
    {
        a *= 3;
        b *= 2;
        if(a > b)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
