#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
pii a[2000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int mode = 0, unr = 0;
    map<int, int> q;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        if(a[i].second != a[i].first)
            mode = 1;
    }
    if(mode)
        cout << "rated" << endl;
    else{
        for(int i = 0; i < n - 1; i++)
            if(a[i].first < a[i + 1].first)
                unr = 1;
        if(unr)
            cout << "unrated" << endl;
        else
            cout << "maybe" << endl;
    }
    
    return 0;
}
