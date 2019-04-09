#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e4 + 10;
pair<int, int> p[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p, p + n);
    
    return 0;
}
