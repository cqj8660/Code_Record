#include <bits/stdc++.h>
using namespace std;
int a[2000], b[2000];
bool vis[2000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string n;
    int k;
    cin >> n >> k;
    int len = (int)n.length();
    int cnt = 0, del = 0;
    for(int i = len - 1; i >= 0; i--)
    {
        if(n[i] == '0')
            cnt++;
        else
            del++;
        if(cnt == k) break;
    }
    if(cnt == k)
        cout << min(del, len - 1) << endl;
    else
        cout << len - 1 << endl;
    return 0;
}
