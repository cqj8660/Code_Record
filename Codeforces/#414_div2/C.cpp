#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
const int maxn = 3e5 + 10;
vector<char> a, b;
char ans[maxn];
int main()
{
    char c;
    while((c = getchar()) != '\n')
        a.push_back(c);
    while((c = getchar()) != '\n')
        b.push_back(c);
    int len = a.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<char>());
    int la = 0, lb = 0;
    int ra = (len + 1) / 2 - 1, rb = len / 2 - 1;
    int l = 0, r = len - 1;
    ans[len]= 0;
    for(int i = 0; i < len; i++)
    {
        if(a[la] < b[lb])
        {
            if(i % 2)
                ans[l++] = b[lb++];
            else
                ans[l++] = a[la++];
        }
        else
        {
            if(i % 2)
                ans[r--] = b[rb--];
            else
                ans[r--] = a[ra--];
        }
    }
    cout << ans << endl;
    return 0;
}
