#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e2 + 10;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll x = 0, y = 0, temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        x += temp;
        
    }
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        y += temp;
    }
    if(x >= y)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
