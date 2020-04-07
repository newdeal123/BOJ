#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <set>
using namespace std;
const int INF=987654321;
typedef long long ll;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    ll op = (ll)a.first*b.second + (ll)b.first*c.second + (ll)c.first*a.second;
    op -= ((ll)a.second*b.first + (ll)b.second*c.first + (ll)c.second*a.first);
    if (op > 0)return 1;
    else if (op == 0)return 0;
    else return -1;
}

bool isIntersect(pair<pair<int, int>, pair<int, int>> x, pair<pair<int, int>, pair<int, int>> y)
{
    pair<int, int> a = x.first;
    pair<int, int> b = x.second;
    pair<int, int> c = y.first;
    pair<int, int> d = y.second;
    int ab = ccw(a, b, c)*ccw(a, b, d);
    int cd = ccw(c, d, a)*ccw(c, d, b);
    if (ab == 0 && cd == 0)
    {
        if (a > b)swap(a, b);
        if (c > d)swap(c, d);
        return (c <= b&&a <= d);
    }
    return (ab <= 0 && cd <= 0);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<pair<pair<int,int>,pair<int,int>>>edge;
    for(int i=0;i<2;i++)
    {
        int x,y,x2,y2;
        cin>>x>>y>>x2>>y2;
        edge.push_back({{x,y},{x2,y2}});
    }
    cout<<isIntersect(edge[0],edge[1]);

}
