#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N,C;
    bool ans=false;
    cin>>N>>C;
    vector<int>v(N);
    for(int i=0;i<N;i++)
    {
        cin>>v[i];
        if(v[i]==C)ans=true;
    }
    sort(v.begin(),v.end());

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
    {
        if(i==j)continue;
        int sum=v[i]+v[j];
        if(sum==C)ans=true;
        if(C<sum || C-sum==v[i] || C-sum==v[j])continue;
        int left=0,right=N-1,ret=0;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(v[mid]+sum>=C)
            {
                right=mid-1;
                ret=mid;
            }
            else left=mid+1;
        }
        if(v[ret]+sum==C)ans=true;
    }

    cout<<ans;
}
