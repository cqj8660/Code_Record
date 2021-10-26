#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 2e5 + 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, h;
    cin >> n >> h;
    double s = h * 1.0 / (2 * n);
    for(int i = 1; i < n; i++)
        cout << setprecision(10) << sqrt(i * 2 * h * s) << endl;
    return 0;
}
