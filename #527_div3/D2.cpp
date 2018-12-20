#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 3e3 + 10;
int a[maxn], b[maxn];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int a, b;
    a = 10;
    b = 5;
    int c = a && b;
    int d = a || b;
    int e = !a;
    printf("%d %d %d\n", c, d, e);
    return 0;
}
