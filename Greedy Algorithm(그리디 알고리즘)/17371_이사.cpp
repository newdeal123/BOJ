#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;

double getDist(pair<int,int>a,pair<int,int>b)
{
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}

int main()
{
    int N;
    cin>>N;
    vector<pair<int,int>>v;
    double ansDist=987654321.0;
    pair<int,int>ans;
    for(int i=0;i<N;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    for(int i=0;i<N;i++)
    {
        pair<int,int>closest=v[i];
        double maxDist=0.0;
        for(int j=0;j<N;j++)
        {
            if(i==j)continue;
            maxDist=max(maxDist,getDist(closest,v[j]));
        }
        if(maxDist<ansDist)
        {
            ans=closest;
            ansDist=maxDist;
        }
    }
    //cout<<ansDist/2.0<<"\n";
    cout<<ans.first<<" "<<ans.second;
}
