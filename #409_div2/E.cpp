#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
map<int, int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        q[a[i]] = 1;
    }
    
    return 0;
}
