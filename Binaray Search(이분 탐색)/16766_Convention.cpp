#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX_N=100000+2;
int N,M,C;
vector<int>t;

bool is_possible(int mid)
{
    int busN=1,last=t[0],lastIdx=0;
    for(int i=1;i<t.size();i++)
    {
        if(t[i]-last>mid || i+1-lastIdx>C)
        {
            busN++;
            last=t[i];
            lastIdx=i;
        }
    }
    if(busN<=M) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M>>C;
    t.resize(N);
    for(int i=0;i<N;i++)cin>>t[i];
    sort(t.begin(),t.end());

    int left=0,right=INF,ret=INF;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(is_possible(mid))
        {
            ret=min(ret,mid);
            right=mid-1;
        }
        else left=mid+1;
    }
    cout<<ret;

}
