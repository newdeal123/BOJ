#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,dontC[201][201]={0,},cnt=0;
    cin>>N>>M;
    while(M--)
    {
        int a,b;
        cin>>a>>b;
        dontC[a][b]=1;
        dontC[b][a]=1;
    }
    for(int i=1;i<=N;i++)
        for(int j=i+1;j<=N;j++)
            for(int k=j+1;k<=N;k++)
                if(!dontC[i][j]&&!dontC[j][k]&&!dontC[k][i])cnt++;
    cout<<cnt;
}
