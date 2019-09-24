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
struct node
{
    string add;
    string next;
    int data;
};
map<string, node> links;
vector<node> linkb, linka;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string l1, l2;
    cin >> l1 >> l2 >> n;
    for(int i = 0; i < n; i++)
    {
        string add, nxt;
        int val;
        cin >> add >> val >> nxt;
        links[add] = node{add, nxt, val};
    }
    int counter = 0;
    string nowL2 = l2;
    while(nowL2 != "-1")
    {
        linkb.push_back(links[nowL2]);
        nowL2 = links[nowL2].next;
    }
    string nowL1 = l1;
    while(nowL1 != "-1")
    {
        linka.push_back(links[nowL1]);
        nowL1 = links[nowL1].next;
    }
    int lena = linka.size(), lenb = linkb.size();
    int p1 = 0, p2 = 0;
    if(lena < lenb)
    {
        vector<node> temp(linka);
        linka.assign(linkb.begin(), linkb.end());
        linkb.assign(temp.begin(), temp.end());
        swap(lena, lenb);
    }
    reverse(linkb.begin(), linkb.end());
    linka.push_back(node{"-1", "-1", -1});
    linkb.push_back(node{"-1", "-1", -1});
    while(p1 < lena || p2 < lenb)
    {
        counter = (counter + 1) % 3;
        if(p2 == lenb)
            counter = 1;
        if(counter == 1)
        {
            cout << linka[p1].add << " " << linka[p1].data << " " << linka[p1].next << endl;
            p1++;
        }
        else if(counter == 2)
        {
            cout << linka[p1].add << " " << linka[p1].data << " " << linkb[p2].add << endl;
            p1++;
        }
        else
        {
            cout << linkb[p2].add << " " << linkb[p2].data << " " << linka[p1].add << endl;
            p2++;
        }
    }

    return 0;
}
