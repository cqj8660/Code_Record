#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define eps 1e-6
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
int n, m;
double put[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 1; i < maxn; i++)
        put[i] = ((i / 2) + 2.0) / (i + 2.0);
    int cas;
    cin >> cas;
    put[0] = 1;
    while(cas--)
    {
        int n;
        string s1, s2;
        cin >> n >> s1 >> s2;
        int a = 0, b = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s1[i] == '1')
                a++;
            if(s2[i] == '1')
                b++;
        }
        int mmin = min(a, b);
        double ans = 0;
        if(a < b)
            ans = put[mmin];
        else if(mmin == 0)
            ans = 0;
        else
            ans = 1 - put[mmin - 1];
        printf("%.18f\n", ans);

    }
    return 0;
}
