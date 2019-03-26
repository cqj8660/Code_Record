#include <bits/stdc++.h>

using namespace std;
const int maxn = 1 << 19;
char a[maxn], b[maxn];
bool cmp(int s1, int e1, int s2, int e2)
{
    for(int i = s1, j = s2; i <= e1; i++, j++)
        if(a[i] != b[j])
            return false;
    return true;
}
bool solve(int s1, int e1, int s2, int e2)
{
    if((e1 - s1 + 1) % 2)
        return cmp(s1, e1, s2, e2);
    int mid1 = (s1 + e1) >> 1, mid2 = (s2 + e2) >> 1;
    return (solve(s1, mid1, s2, mid2) && solve(mid1 + 1, e1, mid2 + 1, e2)) || (solve(s1, mid1, mid2 + 1, e2) && solve(mid1 + 1, e1, s2, mid2));
}
int main()
{
    scanf("%s%s", a, b);
    if(strlen(a) != strlen(b))
    {
        puts("No");
        return 0;
    }
    int len = (int)strlen(a);
    if(cmp(0, len - 1, 0, len - 1))
        cout << "Yes" << endl;
    else
        if(solve(0, len - 1, 0, len - 1))
            puts("Yes");
        else
            puts("No");
    return 0;
}
