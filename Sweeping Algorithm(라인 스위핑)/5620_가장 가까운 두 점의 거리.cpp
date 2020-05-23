#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <set>
#include <math.h>
using namespace std;
const int INF=10000+2;
typedef long long ll;

struct Point{
    int x,y;
};
bool operator < (Point a,Point b){
    if(a.y==b.y)return a.x<b.x;
    else return a.y<b.y;
}

bool compare(Point a,Point b)
{
    return a.x<b.x;
}

ll getDist(Point a,Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,last=0;
    ll ans=0;
    cin>>N;
    vector<Point>v;
    for(int i=0;i<N;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),compare);
    set<Point>candidate={v[0],v[1]};
    ans=getDist(v[0],v[1]);

    for(int i=2;i<N;i++)
    {
        Point now=v[i];
        while(last<i)
        {
            Point p=v[last];
            int dist=abs(now.x-p.x);
            if(dist*dist>ans) candidate.erase(p);
            else break;
            last++;
        }
        Point left={-INF,now.y-(sqrt(ans)+1)},right={INF,now.y+(sqrt(ans)+1)};
        auto leftIt=candidate.lower_bound(left),rightIt=candidate.upper_bound(right);
        for(auto it=leftIt;it!=rightIt;it++)
        {
            ll dist=getDist(now,*it);
            ans=min(ans,dist);
        }
        candidate.insert(now);
    }
    cout<<ans;
}
