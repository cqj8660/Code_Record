#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a = vector<int>(3);
    for(int& idx: a)
        cin >> idx;
    sort(a.begin(), a.end());
    cout << max(0, 1 + a[2] - a[1] - a[0]) << endl;
    return 0;
}
