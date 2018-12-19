#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 3e5 + 10;
int a[maxn], b[maxn];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int maxh = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxh = max(maxh, a[i]);
    }
    for(int i = 0; i < n; i++)
        b[i] = maxh - a[i];
    bool f = 1;
    for(int i = 0; i < n - 1; i++)
    {
        if(b[i] > b[i + 1])
            f = 0;
        else{
            b[i + 1] -= b[i];
        }
    }
    if(f)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
