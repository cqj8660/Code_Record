//
//  C.cpp
//  pureCode
//
//  Created by Qjchen on 2021/11/5.
//

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cas; cin >> cas;
    while(cas--) {
        int n; cin >> n;
        vector<int> bits(32);
        for (int i = 0; i < n; i++) {
            int t; cin >> t;
            for (int j = 0; j < 32; j++) {
                bits[j] += (t >> j) & 1;
            }
        }
        for (int k = 1; k <= n; k++) {
            int flag = 0;
            for (int i = 0 ; i < 32; i++) {
                if (bits[i] % k) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                cout << k << ' ';
            }
        }
        cout << endl;
    }
    return 0;
    
    
}
