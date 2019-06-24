#include <bits/stdc++.h>
using namespace std;
int N,M,L;
vector <int> arr;

bool is_possible(int mid)
{
    int cnt=0;
    cnt+=arr[0]/mid+(arr[0]%mid==0?-1:0);

    for(int i=1;i<arr.size();i++)
    {
        int dist=arr[i]-arr[i-1];
        cnt+=dist/mid+(dist%mid==0?-1:0);
    }
    if(cnt<=M) return true;
    else return false;
}

int main()
{
    cin>>N>>M>>L;
    arr.resize(N);
    for(int i=0;i<N;i++)cin>>arr[i];
    arr.push_back(L);
    sort(arr.begin(),arr.end());

    int left=0,right=1000+2,ret;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(is_possible(mid))
        {
            ret=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    cout<<ret;

}
