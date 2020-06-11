#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const ll INF=987654321987654321;
int N,M;
ll cache[1002][1002];
vector<pair<int,int>>farmer,bessie;

void next(int&nowX,int&nowY,char c)
{
    if(c=='N')nowY++;
    else if(c=='S')nowY--;
    else if(c=='W')nowX--;
    else if(c=='E') nowX++;
}

ll getDist(int idx1,int idx2)
{
    ll dist= (farmer[idx1].first-bessie[idx2].first)*(farmer[idx1].first-bessie[idx2].first)
    +abs(farmer[idx1].second-bessie[idx2].second)*abs(farmer[idx1].second-bessie[idx2].second);
    return dist;
}

ll f(int idx1,int idx2)
{
    if(idx1==N&&idx2==M)return 0;
    ll&ret=cache[idx1][idx2];
    if(ret!=-1)return ret;
    ret=INF;

    if(idx1<N)ret=min(ret,f(idx1+1,idx2)+getDist(idx1+1,idx2));
    if(idx2<M)ret=min(ret,f(idx1,idx2+1)+getDist(idx1,idx2+1));
    if(idx1<N&&idx2<M)ret=min(ret,f(idx1+1,idx2+1)+getDist(idx1+1,idx2+1));

    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>M;
    int x1,y1,x2,y2;
    cin>>x1>>y1;
    farmer.push_back({x1,y1});
    cin>>x2>>y2;
    bessie.push_back({x2,y2});
    string s1,s2;
    cin>>s1>>s2;

    for(auto step:s1)
    {
        next(x1,y1,step);
        farmer.push_back({x1,y1});
    }
    for(auto step:s2)
    {
        next(x2,y2,step);
        bessie.push_back({x2,y2});
    }

    cout<<f(0,0);
}
