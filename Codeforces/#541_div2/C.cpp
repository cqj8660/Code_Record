#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 1e4 + 10;
int a[maxn];
int seq[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    seq[n / 2] = a[0];
    int ptr = 1;
    for(int i = 1; i <= n / 2; i++)
    {
        seq[n / 2 - i] = a[ptr++];
        if(n / 2 + i < n)
            seq[n / 2 + i] = a[ptr++];
    }
    int ans = -1;
    for(int i = 0; i < n; i++)
        cout << seq[i] << ' ';
    cout << endl;
//        ans = max(ans, abs(seq[i] - seq[(i + 1) % n]));
//    cout << ans << endl;
    return 0;
}
