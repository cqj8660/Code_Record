//  B.cpp
//  Created by Qjchen on 2021/10/27.
const int maxn = 2010;
int cnt[maxn];
int ans[maxn][maxn];
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cas;
    scanf("%d", &cas);
    while(cas--) {
        int  n, q, loop = 0;
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ans[0][i]);
        }
        cin >> q;
        for (int i = 0; i < n; i++) {
            int flag = 0;
            for (int j = 0; j < n; j++) {
                cnt[ans[i][j]]++;
            }
            for (int j = 0; j < n; j++) {
                int num = ans[i][j];
                if (cnt[num] != num) {
                    flag = 1;
                }
                ans[i + 1][j] = cnt[num];
            }
            if (flag == 0) {
                loop = i;
                break;
            }
            for (int j = 0; j < n; j++) {
                cnt[ans[i][j]]--;
            }
        }
        while(q--) {
            int x, k;
            scanf("%d%d", &x, &k);
            x--;
            k = min(k, loop);
            cout << ans[k][x] << endl;
        }
    }
    return 0;
    
}
