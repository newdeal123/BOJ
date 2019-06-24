#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1e9+2;
int D,N,M;
vector <int> island;

bool is_possible(int mid)
{
    int last=mid,sum=0;
    for(auto i:island)
    {
        if(last<=i)
        {
            sum++;
            last=i+mid;
        }
    }
    if(sum>=N-M && last<=D) return true;
    else return false;
}

int main()
{
    cin>>D>>N>>M;
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        island.push_back(tmp);
    }
    sort(island.begin(),island.end());
    int left=0,right=MAX_N,ret=0;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(is_possible(mid))
        {
            ret=max(ret,mid);
            left=mid+1;
        }
        else right=mid-1;
    }
    cout<<ret;
}
