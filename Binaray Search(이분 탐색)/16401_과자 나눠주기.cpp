#include <bits/stdc++.h>
using namespace std;
int n,m,snack[1000000+2];

bool is_possible(int len)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=snack[i]/len;

    return sum>=m;
}

int main()
{
    int sum=0;
    cin >> m >>n;
    for(int i=0;i<n;i++)
    {
        cin >>snack[i];
        sum+=snack[i];
    }
    if(sum<m){cout <<"0"; return 0;}

    int left=0,right=1000000000+1,ret=0;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(is_possible(mid))
        {
            ret=max(ret,mid);
            left=mid+1;
        }
        else
            right=mid-1;
    }
    cout <<ret;
}
