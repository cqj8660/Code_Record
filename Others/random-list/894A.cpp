#include<iostream>
//#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 10;
int pre[maxn], suffix[maxn];
int main(){
    string s;
    cin >> s;
    if(s[0] == 'Q')
        pre[0] = 1;
    for(int i = 1; i < s.length(); i++)
    {
        pre[i] += pre[i - 1];
        if(s[i] == 'Q')
            pre[i]++;
    }
    for(int i = (int)s.length() - 1; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1];
        if(s[i] == 'Q')
            suffix[i]++;
    }
    int res = 0;
    for(int i = 0; i < s.length(); i++)
        if(s[i] == 'A')
            res += pre[i] * suffix[i];
    cout << res << endl;
    return 0;
}
