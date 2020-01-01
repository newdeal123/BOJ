#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF=987654321;
int N,cache[5001][5001],arr[5001];

int f(int left,int right)
{
    if(left>=right)return 0;

    int&ret=cache[left][right];
    if(ret!=-1)return ret;

    if(arr[left]==arr[right]) return ret=f(left+1,right-1);
    else return ret=min(f(left+1,right)+1,f(left,right-1)+1);
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N;
    for(int i=0;i<N;i++)cin>>arr[i];
    cout<<f(0,N-1);
}
