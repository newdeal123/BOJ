#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
const int INF = 987654321;
const int MAX_N = 2000 + 2;
int N,C,M,ans=0,capacity[MAX_N]={0,};

struct NODE
{
    int start,end,box;
};

bool compare(NODE a,NODE b)
{
    if(a.end!=b.end)return a.end<b.end;
    else return a.start<b.start;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>C>>M;
    vector<NODE>v;
    while(M--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({a,b,c});
    }
    sort(v.begin(),v.end(),compare);

    for(auto i:v)
    {
        int left=i.start,right=i.end;
        int box=i.box,maxCap=0;
        for(int j=left;j<right;j++)
            maxCap=max(maxCap,capacity[j]);
        int flow=min(box,C-maxCap);

        for(int j=left;j<right;j++)
            capacity[j]+=flow;
        ans+=flow;
    }
    cout<<ans;
}
