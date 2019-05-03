#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<string, ll> mp;
int main()
{
   // freopen("C:\\Users\\stu\\Desktop\\in.txt", "r", stdin);
    char c;
    int n;
    scanf("%d", &n);
    getchar();
    while(n--){
        string res = "";
        while((c = getchar()) != '\n'){
            if(isupper(c))
                res += c;
        }
        mp[res]++;
    }
    ll res = 0;
    for(auto idx: mp){
        res += idx.second * (idx.second - 1) / 2;
    }
    cout << res << endl;
    return 0;
}

