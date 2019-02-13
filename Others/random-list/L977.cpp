#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len = (int)A.size();
        int l = 0, r = 0;
        while(r < len && A[r] < 0)
            r++;
        l = r - 1;
        vector<int> res(len);
        
        int cnt = 0;
        while(l >= 0 && r < len)
        {
            if(A[l] * A[l] < A[r] * A[r])
            {
                res[cnt++] = A[l] * A[l];
                l--;
            }
            else
            {
                res[cnt++] = A[r] * A[r];
                r++;
            }
        }
        while(l >= 0)
        {
            res[cnt++] = A[l] * A[l];
            l--;
        }
        while(r < len)
        {
            res[cnt++] = A[r] * A[r];
            r++;
        }
        return res;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> p;
    p.resize(n);
    for(auto &i: p)
        cin >> i;
    Solution sol;
    vector<int> res = sol.sortedSquares(p);
    for(auto idx: res)
        cout << idx << ' ';
    cout << endl;
    return 0;
}

