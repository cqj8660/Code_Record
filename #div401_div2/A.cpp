#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e4;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    n %= 6;
    int a[] = {0, 1, 2};
    for(int i = 1; i <= n; i++)
        if(i % 2)
            swap(a[0], a[1]);
        else
            swap(a[1], a[2]);
    cout << a[x] << endl;
    return 0;
}
