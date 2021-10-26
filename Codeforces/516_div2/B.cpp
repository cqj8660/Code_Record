#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int t; cin >> t;
        bitset<32> q = bitset<32>(t);
        cout << (1 << q.count()) << endl;
    }
    return 0;
}
