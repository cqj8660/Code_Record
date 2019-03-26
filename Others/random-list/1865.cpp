#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
const int maxn = 1e6 + 10;
bool prime[maxn];
int cnt[maxn];
void init()
{
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;
    for(int i = 2; i <= maxn; i++)
    {
        if(prime[i])
            for(int j = i * 2; j <= maxn; j += i)
                prime[j] = 0;
    }
    cnt[2] = 1;
    for(int i = 3; i <= maxn; i++)
        cnt[i] = cnt[i - 1] + prime[i];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n, m;
    cin >> n >> m;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        if(a >= 1 && a <= m && b >= 1 && b <= m)
            cout << cnt[b] - cnt[a - 1] << endl;
        else
            cout << "Crossing the line" << endl;
    }
    return 0;
}
