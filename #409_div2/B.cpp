#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string x, y;
    cin >> x >> y;
    for(int i = 0; i < x.length(); i++)
    {
        if(y[i] > x[i])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << y << endl;
    return 0;

}
