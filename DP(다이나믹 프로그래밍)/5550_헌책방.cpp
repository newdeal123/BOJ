#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
const int INF=987654321,MAX_N=2000+2;
int N,K,cache[MAX_N][11],pSum[11][MAX_N]={0,};
vector<int>cost[11];

int f(int remain,int genre)
{
    if(remain==0)return 0;
    if(genre==11)return -INF;

    int&ret=cache[remain][genre];
    if(ret!=-1)return ret;
    ret=max(0,f(remain,genre+1));

    for(int i=1;i<=cost[genre].size();i++)
    {
        if(remain>=i)
            ret=max(ret,f(remain-i,genre+1)+pSum[genre][i-1]+(i-1)*i);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache,-1,sizeof(cache));
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        int c,g;
        cin>>c>>g;
        cost[g].push_back(c);
    }
    for(int i=1;i<11;i++)
    {
        if(cost[i].empty())continue;
        sort(cost[i].rbegin(),cost[i].rend());
        pSum[i][0]=cost[i][0];
        for(int j=1;j<cost[i].size();j++)pSum[i][j]=pSum[i][j-1]+cost[i][j];
    }
    cout<<f(K,1);
}
