#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
struct robot
{
    int x, y, f1, f2, f3, f4;
    int cnt = 0;
};
robot rb[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> rb[i].x >> rb[i].y >> rb[i].f1 >> rb[i].f2 >> rb[i].f3 >> rb[i].f4;
            rb[i].cnt = rb[i].f1 + rb[i].f2 + rb[i].f3 + rb[i].f4;
        }
        int lowerx = -100000, lowery = -100000;
        int upx = 100000, upy = 100000;
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            if(rb[i].cnt == 4)
                break;
            if(rb[i].f1 == 0)
            {
                if(upx < rb[i].x)
                    flag = false;
                else
                    lowerx = max(lowerx, rb[i].x);
            }
            if(rb[i].f2 == 0)
            {
                if(lowery > rb[i].y)
                    flag = false;
                else
                    upy = min(upy, rb[i].y);
            }
            if(rb[i].f3 == 0)
            {
                if(lowerx > rb[i].x)
                    flag = false;
                else
                    upx = min(upx, rb[i].x);
            }
            if(rb[i].f4 == 0)
            {
                if(upy < rb[i].y)
                    flag = false;
                lowery = max(lowery, rb[i].y);
            }
        }
        if(flag)
            cout << 1 << " " << upx << " " << upy << endl;
        else
            cout << 0 << endl;

    }
    return 0;
}
