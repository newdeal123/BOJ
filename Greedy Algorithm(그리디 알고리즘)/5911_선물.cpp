#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,B,ret=0;
    cin>>N>>B;
    vector<pair<int,int>> cost,origin;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        origin.push_back(make_pair(a,b));
    }

    for(int i=0;i<N;i++)
    {
        cost=origin;
        cost[i].first=cost[i].first/2;
        vector<int>tmp;
        for(auto it:cost)tmp.push_back(it.first+it.second);
        sort(tmp.begin(),tmp.end());
        int cnt=0,money=B;
        for(int j=0;j<tmp.size();j++)
        {
            if(money-tmp[j]>=0)cnt++,money-=tmp[j];
            else break;
        }
        ret=max(ret,cnt);
    }
    cout<<ret;
}
