#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int len = 0;
    for(int i = 0; i < n; i++)
    {
        int t; cin >> t;
        int temp = t / k;
        if(t % k) temp++;
        len += temp;
    }
    cout << len / 2 + len % 2 << endl;
    return 0;
}
