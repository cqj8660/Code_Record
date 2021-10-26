#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
pii a[2000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p, x, y;
    cin >> p >> x >> y;
    int q = x;
    while(q >= y)
    {
        bool s[510] = {0};
        int i = (q / 50) % 475;
        for(int j = 0; j < 25; j++)
        {
            i = (i * 96 + 42) % 475;
            s[i + 26] = 1;
        }
        if(s[p] && q >= y)
        {
            cout << 0 << endl;
            return 0;
        }
        q -= 50;
    }
    q = x;
    //        i := (s div 50) mod 475
    //        repeat 25 times:
    //        i := (i * 96 + 42) mod 475
    //        print (26 + i)
    while(1){
        bool s[510] = {0};
        int i = (q / 50) % 475;
        for(int j = 0; j < 25; j++)
        {
            i = (i * 96 + 42) % 475;
            s[i + 26] = 1;
        }
        if(s[p] && q >= y)
        {
            cout << (q - x + 50) / 100 << endl;
            break;
        }
        q += 50;
    }
    return 0;
}
