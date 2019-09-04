#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
string s;
const int maxn = 1e3 + 10;
const int maxm = 2e5 + 10;
#define eps 1e-6
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double a, x, y, b, h;
    cin >> a >> x >> y >> b >> h;
    double q = (-y) / (x * x / 4.0);
    double py = q * pow(b - (a + x / 2.0), 2.0) + y;
    if(b < a || b > a + x)
        cout << "YES" << endl;
    else
    {
        if (h - py < -eps)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
