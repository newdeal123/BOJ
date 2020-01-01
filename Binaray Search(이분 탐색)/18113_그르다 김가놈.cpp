#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
int N,K,M;
vector<int>v;

bool is_possible(int mid)
{
    int sum=0;
    for(auto i:v)sum+=i/mid;
    if(sum>=M)return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>K>>M;
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp>=2*K)v.push_back(tmp-2*K);
        else if(tmp>K)v.push_back(tmp-K);
    }
    int left=1,right=(int)1e9+2,ret=-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(is_possible(mid))
        {
            ret=mid;
            left=mid+1;
        }
        else right=mid-1;
    }
    cout<<ret;
}
