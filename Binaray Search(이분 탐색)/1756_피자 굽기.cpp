#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int D,N;
    cin>>D>>N;
    vector<int>v(D);
    for(auto&i:v)cin>>i;
    int minN=v.front();
    for(auto&i:v)
    {
        minN=min(minN,i);
        i=minN;
    }
    int depth=D-1;
    while(N--)
    {
        int w;
        cin>>w;
        int left=0,right=depth,idx=-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(v[mid]>=w)
            {
                idx=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        //cout<<"idx "<<idx<<endl;
        if(idx==-1){cout<<0;return 0;}
        depth=idx-1;
    }
    cout<<depth+2;

}
