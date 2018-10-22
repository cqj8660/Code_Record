<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct point{
    double x, y;
    point(double x = 0, double y = 0):x(x), y(y){}
}a[maxn];
point operator + (point& a, point& b)
{
    return point{a.x + b.x, a.y + b.y};
}
point operator - (point& a, point& b)
{
    return point{a.x - b.x, a.y - b.y};
}
double dis(point a, point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
double cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}
double pointoline(point a, point b, point c)
{
    return fabs(cross(b - a, c - a)) / dis(a, c);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    double ans = 1e12;
    for(int i = 0; i < n; i++)
    {
        ans = min(pointoline(a[(i - 1 + n) % n], a[i], a[(i + 1) % n]) / 2, ans);
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;

=======
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct point{
    double x, y;
    point(double x = 0, double y = 0):x(x), y(y){}
}a[maxn];
double dis(point a, point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
point operator-(point& a, point& b)
{
    return point{a.x - b.x, a.y - b.y};
}
double cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}
double pointoline(point a, point b, point c)
{
    return fabs(cross(b - a, c - a)) / dis(a, c);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    double ans = 1e12;
    for(int i = 0; i < n; i++)
    {
        ans = min(pointoline(a[(i - 1 + n) % n], a[i], a[(i + 1) % n]) / 2, ans);
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
    
>>>>>>> 3d967ecd319259b5a3169ac804d75c38ef759610
}
