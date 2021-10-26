#include <bits/stdc++.h>
#define ll long long
const int maxn = 2e5 + 10;
using namespace std;
int s[maxn];
int main()
{
    int q;
    scanf("%d", &q);
    getchar();
    int l = 0, r = 1;
    for(int i = 0; i < q; i++)
    {
        char c; int v;
        scanf("%c %d", &c, &v);
        getchar();
        if(c == 'L')
            s[v] = l--;
        else if(c == 'R')
            s[v] = r++;
        else
            cout << min(s[v] - l - 1, r - s[v] - 1) << endl;
    }
    return 0;
}
