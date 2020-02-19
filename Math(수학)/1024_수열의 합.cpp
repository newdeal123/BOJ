#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int N,L;
    cin>>N>>L;
    for(int len=L;len<=min(100,N+1);len++)
    {
        if(len%2==0&&(N+len/2)%len==0)
        {
            int mid=(N+len/2)/len;
            if(mid-(len/2)<0)continue;
            for(int i=mid-(len/2);i<mid+(len/2);i++)
                cout<<i<<" ";
                return 0;
        }
        if(len%2==1&&N%len==0)
        {
            int mid=N/len;
            if(mid-(len/2)<0)continue;
            for(int i=mid-(len/2);i<=mid+(len/2);i++)
                cout<<i<<" ";
            return 0;
        }
    }
    cout<<-1;
}
