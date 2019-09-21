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
const int maxn = 2e3 + 10;
int a[maxn];
int cas, n;
void postorder(int id)
{
    if(id * 2 <= n)
        postorder(id * 2);
    if(id * 2 + 1 <= n)
        postorder(id * 2 + 1);
    cout << a[id];
    if(id !=1)
        cout << ' ';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> cas >> n;
    while(cas--)
    {
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        bool flag = true;
        for(int i = 2; i <= n; i++)
        {
            if(a[i / 2] < a[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout << "Max Heap" << endl;
            postorder(1);
            cout << '\n';
            continue;
        }
        flag = true;
        for(int i = 2; i <= n; i++)
        {
            if(a[i / 2] > a[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout << "Min Heap" << endl;
            postorder(1);
            cout << '\n';
            continue;
        }
        cout << "Not Heap" << endl;
        postorder(1);
        cout << '\n';
    }
    return 0;
}
