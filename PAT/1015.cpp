#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
bool isprime[maxn];
void init()
{
    fill(isprime, isprime + maxn, 1);
    isprime[1] = 0;
    for(int i = 2; i < maxn; i++)
    {
        if(isprime[i])
            for(int j = i * 2; j < maxn; j += i)
                isprime[j] = 0;
    }
}
int solve(int n, int d)
{
    int res = 0;
    while(n)
    {
        res = res * d + n % d;
        n /= d;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int d, n;
    while(cin >> n)
    {
        
        if(n < 0)
            break;
        cin >> d;
        int rev = solve(n, d);
        if(isprime[n] && isprime[rev])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        
    }
    return 0;
}
