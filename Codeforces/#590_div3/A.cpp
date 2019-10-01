#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        int n, t, sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++)
            {
                cin >>t;
                sum += t;
            }
        cout << sum / n + !(sum % n == 0) << endl;
    }
    return 0;
}
