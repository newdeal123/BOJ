#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,sum=0,left,right;
    int a,b;
    cin>>N>>a>>b;
    left=a,right=b;
    for(int i=1;i<N;i++)
    {
        cin>>a>>b;
        if(a<=right)
            right=max(b,right);
        else
        {
            sum+=abs(right-left);
            left=a,right=b;
        }
    }
    cout<<sum+abs(right-left);
}
