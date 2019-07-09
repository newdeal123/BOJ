#include<bits/stdc++.h>
using namespace std;
int N,T;
vector<int>v;

bool is_possible(int mid)
{
    priority_queue <int,vector<int>,greater<int>> pq;
    for(int i=0;i<mid;i++)
        pq.push(v[i]);
    for(int i=mid;i<N;i++)
    {
        int tmp=pq.top();
        pq.pop();
        pq.push(tmp+v[i]);
    }
    while(pq.size()>1) pq.pop();
    return pq.top()<=T;
}

int main()
{
    cin>>N>>T;
    v.resize(N);
    for(int i=0;i<N;i++)cin>>v[i];
    int left=1,right=N,ret;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(is_possible(mid))
        {
            ret=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    cout<<ret;
}
