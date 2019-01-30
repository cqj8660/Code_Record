#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define mp make_pair
#define eps 1e-6
#define mo %= MOD
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a % b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, g = 1;
    cin >> n;
    cout << "YES" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i == 0) g = a[i];
        else
            g = gcd(g, a[i]);
    }
    if(g > 1)
        cout << 0 << endl;
    else{
        int cnt = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(a[i] % 2)
            {
                if(a[i + 1] % 2)
                    cnt++;
                else
                    cnt += 2;
                a[i + 1] = 2;
            }
        }
        if(a[n - 1] % 2) cnt+= 2;
        cout << cnt << endl;
    }
    return 0;
}
