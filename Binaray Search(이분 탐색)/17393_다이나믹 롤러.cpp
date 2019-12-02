#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
int N;
vector<ll>a,b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    a.resize(N),b.resize(N);
    for(int i=0;i<N;i++)cin>>a[i];
    for(int i=0;i<N;i++)cin>>b[i];

    for(int i=0;i<N;i++)
    {
        ll now=a[i],left=i,right=N-1,ret;
        while(left<=right)
        {
            ll mid=(left+right)/2;
            if(b[mid]<=now)
            {
                ret=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        cout<<ret-i<<" ";
    }
}
