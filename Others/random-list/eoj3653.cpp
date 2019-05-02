#include <bits/stdc++.h>
const int maxn = 2e3 + 10;
typedef long long ll;
using namespace std;
const int mod = 1e9 + 7;
ll dp[15][15][maxn];
ll suf[maxn][10];
ll comb[maxn][maxn];
void init(){
    comb[0][0] = 1;
    for(int i = 1; i < maxn; i++)
    {
        comb[i][0] = 1;
        for(int j = 1; j < i; j++)
        {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            comb[i][j] %= mod;
        }
        comb[i][i] = 1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    string s;
    cin >> s;
    int q;
    cin >> q;
    int len = (int)s.length();
    for(int i = len - 1; i >= 0; i--){
        for(int j = 0; j < 10; j++)
            suf[i][j] += suf[i + 1][j] + (s[i] == j + '0');
    }
    for(int i = 2; i <= len; i++)
        for(int j = 0; j < len; j++){//枚举每个字符
            for(int k = 0; k < 10; k++){
                dp[s[j] - '0'][k][i] += comb[j][i - 2] * suf[j + 1][k];
                dp[s[j] - '0'][k][i] %= mod;
            }
        }
    while(q--){
        int n; string st;
        cin >> n >> st;
        if(n > len)
            cout << 0 << endl;
        else
            cout << dp[st[0] - '0'][st[1] - '0'][n] << endl;
    }
    return 0;
}

