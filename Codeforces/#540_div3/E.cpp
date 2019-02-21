#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, k;
    scanf("%lld%lld", &n, &k);
    ll mmax = k - 1 + (k - 2) * (k - 1) / 2;
    mmax *= 2;
    if(n > mmax)
        puts("NO");
    else
    {
        puts("YES");
        int counter = 0;
        for(int i = 1; i < k && counter < n; i++)
        {
            for(int j = i + 1; j <= k && counter < n; j++)
            {
                printf("%d %d\n", i, j);
                counter++;
                if(counter == n) break;
                printf("%d %d\n", j, i);
                counter++;
            }
        }
    }
    return 0;
}
