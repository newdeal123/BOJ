#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int N,cache[201][201];
vector<int>v;

int f(int left,int right)
{
    if(left+1==right)return 0;

    int&ret=cache[left][right];
    if(ret!=-1)return ret;
    ret=0;

    for(int i=left+1;i<right;i++)
        ret=max(ret,f(left,i)+f(i,right)+v[left]+v[right]+v[i]);
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(true)
    {
        cin>>N;
        if(!N)break;
        memset(cache,-1,sizeof(cache));
        v.resize(N);
        for(auto&i:v)cin>>i;
        cout<<f(0,N-1)<<"\n";
    }
}
