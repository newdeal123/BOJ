#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int N,cache[101],ans=0;
vector<int>v;

int main()
{
    cin>>N;
    vector<pair<int,int>>tmp;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        tmp.push_back({a,b});
    }
    sort(tmp.begin(),tmp.end());
    v.resize(N);
    for(int i=0;i<N;i++)v[i]=tmp[i].second;
    
    for(int i=0;i<N;i++)
    {
        cache[i]=1;
        for(int j=0;j<N;j++)
            if(v[i]>v[j]&&cache[j]+1>cache[i]) cache[i]=cache[j]+1;
        ans=max(ans,cache[i]);
    }
    ans=N-ans;
    cout<<ans;
}
