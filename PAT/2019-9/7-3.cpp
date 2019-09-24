#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#define ll long long
using namespace std;
const int maxn = 1e3 + 10;
const int maxm = 2e4 + 10;
struct node
{
    string data;
    int lson, rson;
};
node a[maxn];
void post_order(int id)
{
    if(id == -1)
        return;
    cout << "(";
    if(a[id].lson == -1 && a[id].rson != -1)
    {
        cout << a[id].data;
        post_order(a[id].rson);
        cout << ")";
        return;
    }

    if(a[id].rson == -1 && a[id].lson != -1)
    {
        cout << a[id].data;
        post_order(a[id].lson);
        cout << ")";
        return;
    }
    post_order(a[id].lson);
    post_order(a[id].rson);
    cout << a[id].data << ")";
}
int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].data >> a[i].lson >> a[i].rson;
    }
    for(int i = 1; i <= n; i++)
    {
        bool flag = true;
        for(int j = 1; j <= n; j++)
        {
            if(a[j].lson == i || a[j].rson == i)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            post_order(i);
            break;
        }
    }


    return 0;
}
