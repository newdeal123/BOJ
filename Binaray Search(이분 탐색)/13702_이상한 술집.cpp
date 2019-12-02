#include <bits/stdc++.h>
using namespace std;
int N,K;
vector<int>v;

bool is_possible(int mid)
{
    //cout<<"mid="<<mid<<endl;
    int cnt=0;
    for(auto i:v)
    {
        int tmp=i;
        while(true)
        {
            if(tmp<mid) break;
            tmp-=mid;
            cnt++;
        }
    }
    return cnt>=K;
}

int main()
{
    cin>>N>>K;
    v.resize(N);
    for(int i=0;i<N;i++) cin>>v[i];

    int left=1,right=INT_MAX-1,ret;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(is_possible(mid))
        {
            left=mid+1;
            ret=mid;
        }
        else right=mid-1;
    }
    cout<<ret;
}
