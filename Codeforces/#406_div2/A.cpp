#include <bits/stdc++.h>
#define ll long long
using namespace std;
void e_gcd(int a, int b, int &gcd, int &x, int &y)
{
    if(!b)
    {
        x = 1; y = 0; gcd = a;
    }
    else
    {
        e_gcd(b, a % b, gcd, y, x);
        y -= x * (a / b);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d, g;
    int x, y;
    cin >> a >> b >> c >> d;
    e_gcd(a, -c, g, x, y);
    if((d - b) % g)
    {
        cout << -1 << endl;
        return 0;
    }
    x = x * (d - b) / g;//求出方程的x
    //求出最小非负整数x
    //需要x和y均大于0
    x = x % (-c / g);
    if (x < 0)
        x += fabs(-c / g);
    y = ((d - b) - a * x)/(-c);//求出方程的y
    while(y < 0){
        x = x + fabs(-c / g);
        y = ((d - b) - a * x)/(-c);
    }
    cout << b + x * a << endl;
    return 0;
}
