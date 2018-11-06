#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    n--;
    int l = 0, r = 1e9;
    cout << "0 1" << endl;
    string s;
    cin >> s;
    bool mode = 0;
    if(s[0] == 'b')
        mode = 1;
    while(n--)
    {

        int mid = (l + r) / 2;
        cout << mid << " 1" << endl;
        cin >> s;
        if(s[0] == 'b')
        {
            if(mode)
                l = mid;
            else
                r = mid;
        }
        else
        {
            if(mode)
                r = mid;
            else
                l = mid;
        }
    }
    cout << l << " 0 "<< r << " 2" << endl;

    //return 0;
}
