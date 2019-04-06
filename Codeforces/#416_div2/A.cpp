#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int cnt = 1;
    for(int i = 1;;i++)
    {
        if(i % 2)
        {
            a -= cnt++;
            if(a < 0)
            {
                cout << "Vladik" << endl;
                break;
            }
        }
        else
        {
            b -= cnt++;
            if(b < 0)
            {
                cout << "Valera" << endl;
                break;
            }
        }
    }
    return 0;
}
