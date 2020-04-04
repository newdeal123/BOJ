#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
const int INF=987654321;
int N;
double cache[513][513];
vector<pair<int,int>>v;

double getDist(int i,int j)
{
    return sqrt((v[i].first-v[j].first)*(v[i].first-v[j].first)+
                (v[i].second-v[j].second)*(v[i].second-v[j].second));
}

double f(int idx1,int idx2)
{
    double&ret=cache[idx1][idx2];
    if(ret>-0.5)return ret;
    int next=max(idx1,idx2)+1;
    if(next==N-1)return ret=getDist(idx1,next)+getDist(idx2,next);
    ret=min(f(next,idx2)+getDist(idx1,next),f(idx1,next)+getDist(idx2,next));
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed;
    cout.precision(6);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>N;
        memset(cache,-1,sizeof(cache));
        v.clear();
        for(int i=0;i<N;i++)
        {
            int x,y;
            cin>>x>>y;
            v.push_back({x,y});
        }
        cout<<f(0,0)<<"\n";
    }
}
