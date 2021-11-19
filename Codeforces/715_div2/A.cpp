#include <iostream>
using namespace std;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cas;
    cin >> cas;
    while(cas--) {
        string s;
        cin >> s;
        char c = 'z';
        for (char ch: s) {
            c = min(ch, c);
        }
        cout << c << ' ';
        int flag = 0;
        for (char ch: s) {
            if (ch == c && flag == 0) {
                flag = 1;
            }
            else {
                cout << ch;
            }
        }
        cout << endl;
    }
}