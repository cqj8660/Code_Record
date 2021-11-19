//  Created by Qjchen on 2021/11/5.
#include <bits/stdc++.h>
const int MAX = 0x7f7f7f7f;
using namespace std;
int n;
pair<int, int> par[300010];
void getPath(int h) {
    if (h == n) return;
    getPath(par[h].first);
    cout << par[h].second << ' ';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    queue<int> q;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        dp[i] = MAX;
    }
    dp[0] = MAX;
    dp[n] = 0;
    q.push(n);
    int lim = n;
    while(q.size()) {
        int now = q.front();
        q.pop();
        for (int i = now - a[now]; i < lim; i++) {
            // i 是向上跳到的位置 now 是起跳位置
            // i + b[i]是下滑后的位置
            if (dp[i + b[i]] >= MAX) {
                dp[i + b[i]] = dp[now] + 1;
                par[i + b[i]] = {now, i};
                q.push(i + b[i]);
            }
        }
        lim = min(lim, now - a[now]);
    }
    if (dp[0] >= MAX) {
        cout << -1 << endl;
    }
    else {
        cout << dp[0] << endl;
        getPath(0);
    }
    cout << endl;
    return 0;
}
