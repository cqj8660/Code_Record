#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
int l[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int num = 0;
    if(n == 1)
    {
        if(s[0] == 'G')
            cout << 1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        if(s[i] == 'G')
            num++;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'G')
        {
            int j = i, temp = 0;
            while(s[j] == 'G' && j < n)
            {
                temp++;
                j++;
            }
            for(int k = i; k < j; k++)
                l[k] = temp;
            i = j - 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, l[i]);
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'S')
        {
            if(l[i - 1] + l[i + 1] < num)
                ans = max(ans, l[i - 1] + l[i + 1] + 1);
            else
                ans = max(ans, l[i - 1] + l[i + 1]);
        }
    }
    cout << ans << endl;
    return 0;
}
