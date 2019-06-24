#include <bits/stdc++.h>
using namespace std;
int N,M,arr[302];


bool is_possible(int mid,vector<int>&v)
{
    int ret=0,pSum=0;
    for(int i=0;i<N;i++)
    {
        if(mid<arr[i]) return false;
        if(pSum+arr[i]<=mid)
        {
            v[ret]++;
            pSum+=arr[i];
        }
        else
        {
            ret++;
            if(ret+1>M) return false;
            v[ret]++;
            pSum=arr[i];
        }
    }
    if(ret+1<=M) return true;
    else return false;
}

int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)cin>>arr[i];
    vector<int>ans;
    int left=0,right=30000+2,ret=0;
    while(left<=right)
    {
        vector<int>v(M,0);
        int mid=(left+right)/2;
        if(is_possible(mid,v))
        {
            ans=v;
            ret=mid;
            right=mid-1;
        }
        else
            left=mid+1;

    }
    cout<<ret<<endl;
   for(int i=0;i<M;i++)
   {
       if(!ans[i])
       {
           for(int j=0;j<M;j++)
           if(ans[j]>1) {ans[j]--;break;}
           ans[i]++;
       }
   }
   for(auto i:ans)cout<<i<<" ";
}
