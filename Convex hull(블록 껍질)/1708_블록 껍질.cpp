#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
using namespace std;
const int MAX_N=100002;
typedef long long ll;

struct POINT{
    int x,y,p,q;
};
vector<POINT>v;
bool compare(POINT a,POINT b)
{
    if((ll)a.q*b.p!=(ll)a.p*b.q) return (ll)a.q*b.p<(ll)a.p*b.q;
    else if(a.y!=b.y)return a.y<b.y;
    else return a.x<b.x;
}

ll ccw(POINT a,POINT b,POINT c)
{
    return (ll)(a.x*b.y+b.x*c.y+c.x*a.y-b.x*a.y-c.x*b.y-a.x*c.y);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y,1,0});
    }
    sort(v.begin(),v.end(),compare);

    for(int i=1;i<n;i++)
    {
        v[i].p=v[i].x-v[0].x;
        v[i].q=v[i].y-v[0].y;
    }
    sort(v.begin()+1,v.end(),compare);

    stack<int>stk;
    stk.push(0);
    stk.push(1);
    int idx=2;
    while(idx<n)
    {
        while(stk.size()>=2)
        {
            int first,second;
            second=stk.top();
            stk.pop();
            first=stk.top();
            if(ccw(v[first],v[second],v[idx])>0)
            {
                stk.push(second);
                break;
            }
        }
        stk.push(idx++);
    }
    cout<<stk.size();
}
