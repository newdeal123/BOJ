#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
const int INF=987654321;
string s1,s2;
int N,M,ans=INF,cost[4];

int trans(char c)
{
    if(c=='A')return 0;
    else if(c=='C')return 1;
    else if(c=='G')return 2;
    else return 3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>s1>>s2;
    for(int i=0;i<4;i++)cin>>cost[i];
    N=s1.size(),M=s2.size();
    for(int idx1=0;idx1<N;idx1++)
    {
        int sum=0,comp=idx1;
        for(int idx2=0;idx2<M;idx2++)
        {
            if(s1[comp]!=s2[idx2])sum+=cost[trans(s2[idx2])];
            else comp++;
        }
        ans=min(sum,ans);
    }
    cout<<ans;
}
