#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 2e5 + 10;
ll a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int time = 0;
    ll sub = 0;
    for(int j = 0; j <= n && time < k; j++)
    {
        while(a[j] - sub <= 0 && j <= n)
            j++;
        if(j == n + 1) break;
        cout << a[j] - sub << endl;
        time++;
        sub += a[j] - sub;
    }
    for(; time < k; time++)
        cout << 0 << endl;
    return 0;
}
