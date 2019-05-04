#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define eps 1e-6
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int n = 1; n <= 220; n++)
        printf("%f\n", ((n / 2) + 2.0) / (n + 2.0));
    int cas; cin >> cas;
    while(cas--){
        int n;string s1, s2;
        cin >> n >> s1 >> s2;
        int a = 0, b = 0;
        for(int i = 0; i < n; i++)
        {
            if(s1[i] == '1')
                a++;
            if(s2[i] == '1')
                b++;
        }
        n = min(a, b);
        double ans = ((n / 2) + 2.0) / (n + 2.0);
        if(a < b)
            printf("%f\n", ans);
        else
            printf("%f\n", 1 - ans);
    }
}
